#include "Levelmid1.hpp"
#include "Door.hpp"
#include "player.hpp"
#include "Slime.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Wall.hpp"
#include "Melee.hpp"

Physical* wallmid1[2];
Door* toNextLevelmid1;
Player* playermid1;
Actor* enemiesmid1[3];
DeadSoul* speakermid11;

void Levelmid1::LoadScene()
{
    SetBG("SceneBG/stage middle.png", V2(1920, 1080));
    toNextLevelmid1 = new Door;
    toNextLevelmid1->Redirect(LEVELTWO);
    toNextLevelmid1->SetPosition(1900, 500);

    playermid1 = new Player;
    playermid1->SetPosition(100, 350);

    enemiesmid1[0] = new Slime;
    enemiesmid1[0]->SetPosition(600, 150);
    enemiesmid1[1] = new Slime;
    enemiesmid1[1]->SetPosition(1150, 150);
    enemiesmid1[2] = new Slime;
    enemiesmid1[2]->SetPosition(800, 650);

    wallmid1[0] = new Wall;
    wallmid1[0]->SetCollisionSize(V2(350, 1000));
    wallmid1[0]->SetPosition(250, 950);
    wallmid1[0]->Init(RED, V2(550, 300));
    wallmid1[1] = new Wall;
    wallmid1[1]->SetCollisionSize(V2(180, 240));
    wallmid1[1]->SetPosition(250, 120);
    wallmid1[1]->Init(GREEN, V2(550, 300));

    std::string m[6];
    m[0] = "RIDE WIFE";
    m[1] = "LIFE GOOD";
    m[2] = "WIFE FIGHT BACK";
    m[3] = "KILL WIFE";
    m[4] = "WIFE GONE";
    m[5] = "REGRET";
    speakermid11 = new DeadSoul(m, 6);
    speakermid11->SetPosition(300, 350);

    AddPhysical(playermid1);
    AddPhysical(toNextLevelmid1);
    AddPhysical(wallmid1[0]);
    AddPhysical(wallmid1[1]);
    for (auto i : enemiesmid1)
    {
        AddPhysical(i);
        std::cout << i->GetPosition() << std::endl;
    }
    AddPhysical(speakermid11);
}

void Levelmid1::SceneUpdate()
{
    // DEBUG OPTION, MOUSE LEFT PRINTS OUT LOCATION IN SPACE
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
    }
}

void Levelmid1::Collision()
{
    for (auto walls : wallmid1)
        if (CalculateCollisionsBetween(playermid1, walls))
            playermid1->Move(-playermid1->GetVelocity());

    // playermid1 Collision With Border
    if (CalculateCollisionBorder(playermid1))
        playermid1->Move(-playermid1->GetVelocity());

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
        // Collision with Other enemiesmid1
        for (auto eo : enemyList1)
        {
            if (eo == e) // If we are colliding with ourselves, stop doing that
                continue;
            // If colliding with another enemy, stop enemy
            if (CalculateCollisionsBetween(e, eo) || CalculateCollisionsBetween(e, playermid1))
            {
                e->Move(-e->GetVelocity());
            }
        }

        // Enemy and Wall Collision
        for (auto walle : wallmid1)
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
            if (CalculateCollisionsBetween(e, mel))
            {
                e->Hurt(temp->GetDamage());
            }
        }
    }
}
