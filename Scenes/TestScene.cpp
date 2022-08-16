#include "TestScene.hpp"
#include "Player.hpp"
#include "StaticBody.hpp"

TestScene::TestScene()
{
    Image ptemp = GenImageColor(128,128,BLUE);
    Player* playerCharacter = new Player(ptemp);
    Image temp = GenImageColor(128,128,RED);
    StaticBody* Wall = new StaticBody(temp);
    UnloadImage(temp);
    AddEntity(playerCharacter);
    AddEntity(Wall);
    SetBGColor(GRAY);
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
        std::cout << "COLLIDED" << std::endl;
    }
}
