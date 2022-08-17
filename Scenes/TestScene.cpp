#include "TestScene.hpp"
#include "Player.hpp"
#include "Slime.hpp"
#include "Wall.hpp"

TestScene::TestScene()
{
    Player* playerCharacter = new Player();
    Slime* EnemySlime = new Slime();
    Wall* wall = new Wall();


    AddEntity(playerCharacter);
    AddEntity(wall);
    AddEntity(EnemySlime);
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
