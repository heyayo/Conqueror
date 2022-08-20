#include "TestScene.hpp"
#include "Player.hpp"
#include "Slime.hpp"
#include "Wall.hpp"
#include "TextBox.hpp"
#include "Skeleton.hpp"
#include "Undead.hpp"
#include "Door.hpp"

Player* playerCharacter;
Slime* EnemySlime;
Wall* wall;
Skeleton* EnemySkele;
Undead* EnemyUndead;
TextBox* testBox;
Door* testDoor;

float temp = 0;
void TestScene::SceneUpdate()
{
    temp += IsKeyDown(KEY_R) - IsKeyDown(KEY_F);
    testBox->SetRotation(temp);
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
    if (CalculateCollisionsBetween(PlayerPtr, GetPhysicsByIndex(3)) || CalculateCollisionBorder(PlayerPtr))
    {
        PlayerPtr->Move(-PlayerPtr->GetVelocity());
    }
    if (CalculateCollisionsBetween(PlayerPtr, GetPhysicsByIndex(4)) || CalculateCollisionBorder(PlayerPtr))
    {
        PlayerPtr->Move(-PlayerPtr->GetVelocity());
    }
    std::vector<Physical*> temp = GetPhysicsByGroup("PROJECTILE");
    for (int i = 0; i < temp.size(); i++)
    {
        if (CalculateCollisionBorder(static_cast<Physical*>(temp[i])))
            Kill(temp[i]);
    }
}

void TestScene::LoadScene()
{
    playerCharacter = new Player;
    EnemySlime = new Slime;
    wall = new Wall();
    EnemySkele = new Skeleton;
    EnemyUndead = new Undead;
    testBox = new TextBox("TEXT MESSAGE IN A BOX");
    testDoor = new Door();

    testBox->SetPosition(1000,500);
    testBox->SetAlignment(TextBox::CENTER);
    testBox->SetPadding(V2(200,200));

    SetBG("SceneBG/wallpaper.png");
    AddPhysical(playerCharacter);
    AddPhysical(wall);
    AddPhysical(EnemySlime);
    AddPhysical(EnemySkele);
    AddPhysical(EnemyUndead);
    AddPhysical(testDoor);
    AddUI(testBox);
}
