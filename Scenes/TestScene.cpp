#include "TestScene.hpp"
#include "Player.hpp"

TestScene::TestScene()
{
    Player* playerCharacter = new Player("sprites/archer_attack.png", 128,128);
    AddEntity(playerCharacter);
    SetBGColor(GRAY);
}

void TestScene::SceneRun()
{
    SceneDraw();
}
