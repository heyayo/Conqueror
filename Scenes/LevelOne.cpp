#include "LevelOne.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Slime.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "LevelTwo.hpp"
#include "Wall.hpp"
#include "Melee.hpp"

Physical* wall1[2];
Door* toNextLevel;
Player* player;
Actor* enemies[3];
DeadSoul* speaker;

void LevelOne::LoadScene()
{
    SetBG("SceneBG/stage_1.png",V2(1920,1080));
    toNextLevel = new Door;
    toNextLevel->Redirect(LEVELTWO);
    toNextLevel->SetPosition(1000,500);

    player = new Player;
    player->SetPosition(100,350);

    enemies[0] = new Slime;
    enemies[0]->SetPosition(600,150);
    enemies[1] = new Slime;
    enemies[1]->SetPosition(1150,150);
    enemies[2] = new Slime;
    enemies[2]->SetPosition(800,650);

    wall1[0] = new Wall;
    wall1[0]->SetCollisionSize(V2(350, 1000));
    wall1[0]->SetPosition(250, 950);
    wall1[0]->Init(RED, V2(550, 300));
    wall1[1] = new Wall;
    wall1[1]->SetCollisionSize(V2(180, 240));
    wall1[1]->SetPosition(250, 120);
    wall1[1]->Init(GREEN, V2(550, 300));

    std::string m[6];
    m[0] = "RIDE WIFE";
    m[1] = "LIFE GOOD";
    m[2] = "WIFE FIGHT BACK";
    m[3] = "KILL WIFE";
    m[4] = "WIFE GONE";
    m[5] = "REGRET";
    speaker = new DeadSoul(m,6);
    speaker->SetPosition(300,350);

    AddPhysical(player);
    AddPhysical(toNextLevel);
    AddPhysical(wall1[0]);
    AddPhysical(wall1[1]);
    for (auto i : enemies)
    {
        AddPhysical(i);
        std::cout << i->GetPosition() << std::endl;
    }
    AddPhysical(speaker);
}

void LevelOne::SceneUpdate()
{
    // DEBUG OPTION, MOUSE LEFT PRINTS OUT LOCATION IN SPACE
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
    }
}

void LevelOne::Collision()
{
    for (auto walls : wall1)
        if (CalculateCollisionsBetween(player,walls))
            player->Move(-player->GetVelocity());

    // Player Collision With Border
    if (CalculateCollisionBorder(player))
        player->Move(-player->GetVelocity());

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
            if (CalculateCollisionsBetween(arrow, e))
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
            if (CalculateCollisionsBetween(e,eo) || CalculateCollisionsBetween(e,player))
            {
                e->Move(-e->GetVelocity());
            }
        }

        // Enemy and Wall Collision
        for (auto walle : wall1)
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
