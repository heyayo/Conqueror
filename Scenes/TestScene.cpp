#include "TestScene.hpp"
#include "Player.hpp"
#include "Slime.hpp"
#include "Wall.hpp"
#include "TextBox.hpp"

UIElement* textBox;

TestScene::TestScene()
{
    Player* playerCharacter = new Player();
    Slime* EnemySlime = new Slime();
    Wall* wall = new Wall();

    AddEntity(playerCharacter);
    AddEntity(wall);
    AddEntity(EnemySlime);

    TextBox* testBox = new TextBox("TEST MESSAGE IN BOX");
    testBox->SetPosition(1000,500);
    testBox->SetAlignment(TextBox::CENTER);
    testBox->SetPadding(V2(200,200));
    AddUI(testBox);
    textBox = testBox;
    SetBG("SceneBG/wallpaper.png");
}

float temp = 0;
void TestScene::SceneUpdate()
{
    temp += IsKeyDown(KEY_R) - IsKeyDown(KEY_F);
    textBox->SetRotation(temp);
    SceneDraw();
    Collision();
}

void TestScene::Collision()
{
    Player* PlayerPtr = static_cast<Player*>(GetPhysicsByIndex(0));
    if (CalculateCollisionsBetween(PlayerPtr, GetPhysicsByIndex(1)) || CalculateCollisionBorder(PlayerPtr))
    {
        PlayerPtr->Move(-PlayerPtr->GetVelocity());
    }
    if (CalculateCollisionsBetween(PlayerPtr, GetPhysicsByIndex(2)) || CalculateCollisionBorder(PlayerPtr))
    {
        PlayerPtr->Move(-PlayerPtr->GetVelocity());
    }
    std::vector<Entity*> temp = GetPhysicsByGroup("PROJECTILE");
    for (int i = 0; i < temp.size(); i++)
    {
        if (CalculateCollisionBorder(static_cast<Physical*>(temp[i])))
            Kill(temp[i]);
    }
}
