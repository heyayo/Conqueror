#include "LevelThree.h"
#include "Door.hpp"
#include "Player.hpp"
#include "Skeleton.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Physical.hpp"
#include "Wall.hpp"

Physical* wall3[3];
Door* toNextLevel3;
Player* player3;
Actor* enemies3[5];
DeadSoul* speaker3;

void LevelThree::LoadScene()
{
    SetBG("SceneBG/stage_3.png", V2(1920, 1080));
    toNextLevel3 = new Door;
    toNextLevel3->Redirect(LEVELFOUR);
    toNextLevel3->SetPosition(1300, 500);

    player3 = new Player;
    player3->SetPosition(100, 350);

    enemies3[0] = new Skeleton;
    enemies3[0]->SetPosition(850, 250);
    enemies3[1] = new Skeleton;
    enemies3[1]->SetPosition(950, 350);
    enemies3[2] = new Skeleton;
    enemies3[2]->SetPosition(1150, 600);
    enemies3[3] = new Skeleton;
    enemies3[3]->SetPosition(1150, 200);
    enemies3[4] = new Skeleton;
    enemies3[4]->SetPosition(900, 300);

    wall3[0] = new Wall;
    wall3[0]->SetCollisionSize(V2(650, 1000));
    wall3[0]->SetPosition(1070, 700);
    wall3[0]->Init(RED, V2(260, 750));
    wall3[1] = new Wall;
    wall3[1]->SetCollisionSize(V2(180, 240));
    wall3[1]->SetPosition(400, 950);
    wall3[1]->Init(GREEN, V2(1100, 240));
    std::string m[6];
    m[0] = "RIDE WIFE";
    m[1] = "LIFE GOOD";
    m[2] = "WIFE FIGHT BACK";
    m[3] = "KILL WIFE";
    m[4] = "WIFE GONE";
    m[5] = "REGRET";
    speaker3 = new DeadSoul(m, 6);
    speaker3->SetPosition(300, 350);

    AddPhysical(player3);
    AddPhysical(toNextLevel3);
    AddPhysical(wall3[0]);
    AddPhysical(wall3[1]);
    for (auto i : enemies3)
    {
        AddPhysical(i);
        std::cout << i->GetPosition() << std::endl;
    }
    AddPhysical(speaker3);
}

void LevelThree::SceneUpdate()
{
    std::vector<Actor*> enemylist = GetActorsByGroup("ENEMY");
    for (auto enemy : enemylist)
    {
        dynamic_cast<Enemy*>(enemy)->Act();
        if (enemy->GetHealth() <= 0)
            Kill(enemy);
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
}

void LevelThree::Collision()
{
    if (CalculateCollisionBorder(player3))
    {
        player3->Move(-player3->GetVelocity());
    }
    if (CalculateCollisionsBetween(player3, wall3[0]))
    {
        player3->Move(-player3->GetVelocity());
    }
    for (int i = 0; i < 6; i++)
    {
        if (CalculateCollisionsBetween(enemies3[i], wall3[0]))
        {
            enemies3[i]->Move(-enemies3[i]->GetVelocity());
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (CalculateCollisionsBetween(enemies3[i], wall3[1]))
        {
            enemies3[i]->Move(-enemies3[i]->GetVelocity());
        }
    }
    if (CalculateCollisionsBetween(player3, wall3[1]))
    {
        player3->Move(-player3->GetVelocity());
    }
    std::vector<Actor*> arrows = GetActorsByGroup("PROJECTILE");
    std::vector<Actor*> enemyList = GetActorsByGroup("ENEMY");
    for (auto arrow : arrows)
    {
        if (CalculateCollisionBorder(arrow))
            Kill(arrow);
        for (auto enemy : enemyList)
        {
            if (CalculateCollisionsBetween(arrow, enemy))
            {
                enemy->Hurt(arrow->GetDamage());
                Kill(arrow);
                std::cout << enemy->GetHealth() << std::endl;
            }
        }
    }
}