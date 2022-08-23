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
Actor* enemies3[3];
DeadSoul* speaker3;

void LevelThree::LoadScene()
{
    SetBG("SceneBG/stage_3.png", V2(1920, 1080));
    toNextLevel3 = new Door;
    toNextLevel3->Redirect(MAINMENU);
    toNextLevel3->SetPosition(1000, 500);

    player3 = new Player;
    player3->SetPosition(100, 350);

    wall3[0] = new Wall;
    wall3[0]->SetCollisionSize(V2(700, 1000));
    wall3[0]->SetPosition(840, 780);
    wall3[0]->Init(BLACK, V2(300, 540));
    wall3[1] = new Wall;
    wall3[1]->SetCollisionSize(V2(180, 240));
    wall3[1]->SetPosition(840, 120);
    wall3[1]->Init(GREEN, V2(240, 180));
    speaker3 = new DeadSoul("TEST MESSAGE I WANT TO DIE");
    speaker3->SetPosition(300, 350);

    enemies3[0] = new Skeleton;
    enemies3[0]->SetPosition(480, 150);
    enemies3[1] = new Skeleton;
    enemies3[1]->SetPosition(1150, 150);
    enemies3[2] = new Skeleton;
    enemies3[2]->SetPosition(750, 500);

    speaker3 = new DeadSoul("TEST MESSAGE I WANT TO DIE");
    speaker3->SetPosition(300, 350);

    if (CalculateCollisionsBetween(player3, wall3[1]))
    {
        player3->Move(-player3->GetVelocity());
    }

    AddPhysical(player3);
    AddPhysical(toNextLevel3);
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
        player3->Move(-player3->GetVelocity());
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
