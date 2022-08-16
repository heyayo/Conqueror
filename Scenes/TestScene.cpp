#include "TestScene.hpp"
#include "Player.hpp"
#include "Wall.hpp"

TestScene::TestScene()
{
    Image ptemp = GenImageColor(128,128,BLUE);
    Player* playerCharacter = new Player();
    Image temp = GenImageColor(128,128,RED);
    Wall* wall = new Wall();

    playerCharacter->Init(ptemp);
    wall->Init(temp);

    AddEntity(playerCharacter);
    AddEntity(wall);
    SetBGColor(GRAY);
    UnloadImage(temp);
    UnloadImage(ptemp);
}

void TestScene::SceneRun()
{
    SceneDraw();
    Collision();
}

void TestScene::Collision()
{
    Player* PlayerPtr = static_cast<Player*>(GetPhysicsByIndex(0));
    if (CalculateCollisionsBetween(PlayerPtr, GetPhysicsByIndex(1)))
    {
        PlayerPtr->Move(-PlayerPtr->GetVelocity());
    }
}

TestScene::~TestScene()
{
}
