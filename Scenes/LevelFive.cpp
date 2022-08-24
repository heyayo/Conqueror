#include "LevelFive.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "LevelFive.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Dragon.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Melee.hpp"
#include "Wall.hpp"

Physical* wall5[2];
Door* toNextLevel5;
Player* player5;
Actor* enemies5[1];
DeadSoul* speaker5;

void LevelFive::LoadScene()
{
    SetBG("SceneBG/stage Final.png", V2(1920, 1080));
    toNextLevel5 = new Door;
    toNextLevel5->Redirect(MAINMENU);
    toNextLevel5->SetPosition(1000, 500);

    player5 = new Player;
    player5->SetPosition(100, 350);

    enemies5[0] = new Dragon;
    enemies5[0]->SetPosition(1300, 540);
 

    wall5[0] = new Wall;

    wall5[0]->SetCollisionSize(V2(550, 300));
    wall5[0]->SetPosition(220, 980);
    wall5[0]->Init(RED, V2(460, 230));
    wall5[1] = new Wall;
    wall5[1]->SetCollisionSize(V2(550, 300));
    wall5[1]->SetPosition(220, 90);
    wall5[1]->Init(GREEN, V2(460, 240));


    wall5[0]->SetCollisionSize(V2(350, 1000));  
    wall5[0]->SetPosition(250, 950);
    wall5[0]->Init(RED, V2(550, 300));
    wall5[1] = new Wall;
    wall5[1]->SetCollisionSize(V2(180, 240));
    wall5[1]->SetPosition(250, 120);
    wall5[1]->Init(GREEN, V2(550, 300));

    std::string m[6];
    m[0] = "RIDE WIFE";
    m[1] = "LIFE GOOD";
    m[2] = "WIFE FIGHT BACK";
    m[3] = "KILL WIFE";
    m[4] = "WIFE GONE";
    m[5] = "REGRET";
    speaker5 = new DeadSoul(m,6);
    speaker5->SetPosition(300, 350);

    AddPhysical(player5);
    AddPhysical(toNextLevel5);
    AddPhysical(wall5[0]);
    AddPhysical(wall5[1]);
    for (auto i : enemies5)
    {
        AddPhysical(i);
        std::cout << i->GetPosition() << std::endl;
    }
    AddPhysical(speaker5);
}

void LevelFive::SceneUpdate()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
}

void LevelFive::Collision()
{
    for (auto walls : wall5)
        if (CalculateCollisionsBetween(player5,walls))
            player5->Move(-player5->GetVelocity());

    // Player Collision With Border
    if (CalculateCollisionBorder(player5))
        player5->Move(-player5->GetVelocity());

    // Enemy Collision With Arrows
    std::vector<Actor*> arrows = GetActorsByGroup("PROJECTILE");
    std::vector<Actor*> EnemyFireballs = GetActorsByGroup("ENEMYPROJECTILE");
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
        Dragon* enemyconv = dynamic_cast<Dragon*>(e);
        enemyconv->Act();
        enemyconv->LookAt(player5);
        for (auto arrow : arrows)
        {
            // Kill Arrow on Border Collision
            if (CalculateCollisionBorder(arrow))
            {
                Kill(arrow);
                std::cout << "BORDER HIT" << std::endl;
            }
            // Kill Arrow and Hurt Enemy on Enemy Collision
            if (CalculateCollisionsBetween(arrow, e))
            {
                std::cout << "HIT" << std::endl;
                e->Hurt(arrow->GetDamage());
                Kill(arrow);
            }
        }
        for (auto EnemyFireball : EnemyFireballs)
        {
            // Kill EnemyFireball on Border Collision
            if (CalculateCollisionBorder(EnemyFireball))
            {
                Kill(EnemyFireball);
                std::cout << "BORDER HIT" << std::endl;
            }
            // Kill EnemyFireball and Hurt Enemy on Enemy Collision
            else if (CalculateCollisionsBetween(EnemyFireball, player5))
            {
                std::cout << "HIT" << std::endl;
                player5->Hurt(EnemyFireball->GetDamage());
                Kill(EnemyFireball);
            }
        }
        // Collision with Other Enemies
        for (auto eo : enemyList1)
        {
            if (eo == e) // If we are colliding with ourselves, stop doing that
                continue;
            // If colliding with another enemy, stop enemy
            if (CalculateCollisionsBetween(e, eo) || CalculateCollisionsBetween(e, player5))
            {
                e->Move(-e->GetVelocity());
            }
        }
        // Enemy and Wall Collision
        for (auto walle : wall5)
        {
            if (CalculateCollisionsBetween(walle, e))
                e->Move(-e->GetVelocity());
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
            if (CalculateCollisionsBetween(e,mel))
            {
                e->Hurt(temp->GetDamage());
            }
        }
    }
}