#include "LevelThree.h"
#include "Door.hpp"
#include "Player.hpp"
#include "Skeleton.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Melee.hpp"
#include "Physical.hpp"
#include "Wall.hpp"

Physical* wall3[2];
Door* toNextLevel3;
Player* player3;
Actor* enemies3[5];
DeadSoul* speaker3;

void LevelThree::LoadScene()
{
    SetBG("SceneBG/stage_3.png", V2(1920, 1080));
    toNextLevel3 = new Door;
    toNextLevel3->Redirect(LEVELFOUR);
    toNextLevel3->SetPosition(1500, 500);

    player3 = new Player;
    player3->SetPosition(100, 350);

    enemies3[0] = new Skeleton;
    enemies3[0]->SetPosition(1100, 250);
    enemies3[1] = new Skeleton;
    enemies3[1]->SetPosition(100, 350);
    enemies3[2] = new Skeleton;
    enemies3[2]->SetPosition(1150, 600);
    enemies3[3] = new Skeleton;
    enemies3[3]->SetPosition(1130, 200);
    enemies3[4] = new Skeleton;
    enemies3[4]->SetPosition(1120, 300);

    wall3[0] = new Wall;
    wall3[0]->SetCollisionSize(V2(650, 1000));
    wall3[0]->SetPosition(1070, 740);
    wall3[0]->Init(RED, V2(240, 750));
    wall3[1] = new Wall;
    wall3[1]->SetCollisionSize(V2(180, 240));
    wall3[1]->SetPosition(400, 930);
    wall3[1]->Init(GREEN, V2(1100, 220));
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
    }
    AddPhysical(speaker3);
}

void LevelThree::SceneUpdate()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
}

void LevelThree::Collision()
{
    for (auto walls : wall3)
        if (CalculateCollisionsBetween(player3, walls))
            player3->Move(-player3->GetVelocity());

    // Player Collision With Border
    if (CalculateCollisionBorder(player3))
        player3->Move(-player3->GetVelocity());

    // Enemy Collision With Arrows
    std::vector<Actor*> arrows = GetActorsByGroup("PROJECTILE");
    std::vector<Actor*> enemyList1 = GetActorsByGroup("ENEMY");

    // Enemy Collisions
    for (auto e : enemyList1)
    {
        // Tick Enemy AI and Kill if Health Depleted
        if (e->GetHealth() <= 0)
        {
            Kill(e);
            continue;
        }
        Enemy* enemyconv = dynamic_cast<Enemy*>(e);
        enemyconv->Act();
        for (auto arrow : arrows)
        {
            // Kill Arrow on Border Collision
            if (CalculateCollisionBorder(arrow))
            {
                Kill(arrow);
                std::cout << "BORDER HIT" << std::endl;
            }
            // Kill Arrow and Hurt Enemy on Enemy Collision
            else if (CalculateCollisionsBetween(arrow, e))
            {
                std::cout << "HIT" << std::endl;
                e->Hurt(arrow->GetDamage());
                Kill(arrow);
            }
        }
        // Collision with Other Enemies
        for (auto eo : enemyList1)
        {
            if (eo == e) // If we are colliding with ourselves, stop doing that
                continue;
            // If colliding with another enemy, stop enemy
            if (CalculateCollisionsBetween(e, eo) || CalculateCollisionsBetween(e, player3))
            {
                e->Move(-e->GetVelocity());
            }
        }

        // Enemy and Wall Collision
        for (auto walle : wall3)
        {
            if (CalculateCollisionsBetween(walle, e))
            {
                e->Move(-e->GetVelocity());
                std::cout << "test";
            }
        }
    }

    // Melee Collision Checking
    std::vector<Physical*> melee = GetPhysicsByGroup("MELEE");
    for (auto mel : melee)
    {
        Melee* temp = static_cast<Melee*>(mel);
        if (temp->cooldown >= temp->maxCooldown)
            Kill(mel);
        for (auto e : enemyList1)
        {
            if (CalculateCollisionsBetween(e, mel))
            {
                e->Hurt(temp->GetDamage());
            }
        }
    }
}