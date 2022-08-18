#include "TestScene.hpp"
#include "Player.hpp"
#include "Wall.hpp"
#include "TextBox.hpp"

TestScene::TestScene()
{
    Player* playerCharacter = new Player();
    Wall* wall = new Wall();

    AddEntity(playerCharacter);
    AddEntity(wall);

    TextBox* testBox = new TextBox("TEST MESSAGE IN BOX", WHITE,18);
    testBox->Init(GREEN,V2(500,500));
    testBox->SetPosition(1000,500);
    testBox->SetAlignment(TextBox::CENTER);
    AddUI(testBox);

    SetBG(Color{75,75,75,255});
}

void TestScene::SceneUpdate()
{
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
    std::vector<Entity*> temp = GetPhysicsByGroup("PROJECTILE");
    for (int i = 0; i < temp.size(); i++)
    {
        if (CalculateCollisionBorder(static_cast<Physical*>(temp[i])))
            Kill(temp[i]);
    }
}
