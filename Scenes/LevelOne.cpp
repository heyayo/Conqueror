#include "LevelOne.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Slime.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Wall.hpp"
#include "Melee.hpp"
#include "Bar.hpp"

Physical* wall1[2];
Door* toNextLevel;
Actor* enemies[3];
DeadSoul* speaker;
Player* player;
Bar* enemyHealthBar[3];

void LevelOne::LoadScene()
{
    SetBG("SceneBG/stage_1.png",V2(1920,1080));
    toNextLevel = new Door;
    toNextLevel->Redirect(LEVELMID1);
    toNextLevel->SetPosition(1000,500);

    player = new Player;
    player->SetPosition(200,200);
    enemies[0] = new Slime;
    enemies[0]->SetPosition(600,150);
    enemies[1] = new Slime;
    enemies[1]->SetPosition(1150,150);
    enemies[2] = new Slime;
    enemies[2]->SetPosition(800,650);
    for (int i = 0; i < 3; i++)
    {
        enemyHealthBar[i] = new Bar(enemies[i]->GetHealthPtr(),
                                    10,
                                    GREEN,
                                    enemies[i]->GetSize().x,
                                    5);
        AddUI(enemyHealthBar[i]);
    }

    wall1[0] = new Wall;
    wall1[0]->SetCollisionSize(V2(350, 1000));
    wall1[0]->SetPosition(250, 950);
    wall1[0]->Init(RED, V2(550, 300));
    wall1[1] = new Wall;
    wall1[1]->SetCollisionSize(V2(180, 240));
    wall1[1]->SetPosition(250, 120);
    wall1[1]->Init(GREEN, V2(550, 300));

    std::string m[6];
    m[0] = "Are these slimes really what the adventurer";
    m[1] = " died to? Do they really think that ";
    m[2] = " they can scare me through numbers alone?";
    m[3] = " I will show them what I am capable of!";
    speaker = new DeadSoul(m,6);
    speaker->SetPosition(300,350);

    AddPhysical(player);
    AddPhysical(toNextLevel);
    AddPhysical(wall1[0]);
    AddPhysical(wall1[1]);
    for (auto i : enemies)
    {
        AddPhysical(i);
    }
    AddPhysical(speaker);
}

void LevelOne::SceneUpdate()
{
    std::cout << GetPlayersClass() << std::endl;
    for (int i = 0; i < 3; i++)
    {
        V2 barOffset(0,enemies[i]->GetSize().y/2);
        enemyHealthBar[i]->SetPosition(enemies[i]->GetPosition()+barOffset);
    }

    // DEBUG OPTION, MOUSE LEFT PRINTS OUT LOCATION IN SPACE
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
    }
}

void LevelOne::Collision()
{
    for (auto walls : wall1)
        if (CalculateCollisionsBetween(player, walls))
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
            }
            // Kill Arrow and Hurt Enemy on Enemy Collision
            if (CalculateCollisionsBetween(arrow, e))
            {
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
            if (CalculateCollisionsBetween(e,eo) || CalculateCollisionsBetween(e, player))
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
