#include "LevelTwo.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Goblin.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Melee.hpp"
#include "Physical.hpp"
#include "Wall.hpp"
#include "Bar.hpp"

Physical* wall2[2];
Door* toNextLevel1;
Player* player1;
Actor* enemies1[5];
DeadSoul* speaker1;
Bar* ebars2[5];

void LevelTwo::LoadScene()
{
    SetBG("SceneBG/stage_2.png", V2(1920, 1080));
    toNextLevel1 = new Door;
    toNextLevel1->Redirect(LEVELTHREE);
    toNextLevel1->SetPosition(1200, 500);

    player1 = new Player;
    player1->SetPosition(100, 350);

    enemies1[0] = new Goblin;
    enemies1[0]->SetPosition(850, 250);
    enemies1[1] = new Goblin;
    enemies1[1]->SetPosition(950, 350);
    enemies1[2] = new Goblin;
    enemies1[2]->SetPosition(1150, 600);
    enemies1[3] = new Goblin;
    enemies1[3]->SetPosition(1150, 200);
    enemies1[4] = new Goblin;
    enemies1[4]->SetPosition(900, 300);
    for (int i = 0; i < 5; i++)
    {
        ebars2[i] = new Bar(enemies1[i]->GetHealthPtr(),
                                    10,
                                    GREEN,
                                    enemies1[i]->GetSize().x,
                                    5);
        AddUI(ebars2[i]);
    }

    wall2[0] = new Wall;
    wall2[0]->SetCollisionSize(V2(650,1000));
    wall2[0]->SetPosition(840,780);
    wall2[0]->Init(BLACK, V2(350, 580));
    wall2[1] = new Wall;
    wall2[1]->SetCollisionSize(V2(180, 240));
    wall2[1]->SetPosition(840, 120);
    wall2[1]->Init(GREEN, V2(330, 220));
    std::string m[6];
    m[0] = "RIDE WIFE";
    m[1] = "LIFE GOOD";
    m[2] = "WIFE FIGHT BACK";
    m[3] = "KILL WIFE";
    m[4] = "WIFE GONE";
    m[5] = "REGRET";
    speaker1 = new DeadSoul(m, 6);
    speaker1->SetPosition(300, 350);

    AddPhysical(player1);
    AddPhysical(toNextLevel1);
    AddPhysical(wall2[0]);
    AddPhysical(wall2[1]);
    for (auto i : enemies1)
    {
        AddPhysical(i);
    }
    AddPhysical(speaker1);
}

void LevelTwo::SceneUpdate()
{
    for (int i = 0; i < 5; i++)
    {
        V2 barOffset(0,enemies1[i]->GetSize().y/2);
        ebars2[i]->SetPosition(enemies1[i]->GetPosition()+barOffset);
    }
    // DEBUG OPTION, MOUSE LEFT PRINTS OUT LOCATION IN SPACE
    /*if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
    }*/
}

void LevelTwo::Collision()
{
    for (auto walls : wall2)
        if (CalculateCollisionsBetween(player1,walls))
            player1->Move(-player1->GetVelocity());

    // Player Collision With Border
    if (CalculateCollisionBorder(player1))
        player1->Move(-player1->GetVelocity());

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
            else {
                for (auto walle : wall2)
                {
                    if (CalculateCollisionsBetween(walle, arrow))
                        Kill(arrow);
                    std::cout << "WALL HIT" << std::endl;
                }
            }
        }
        // Collision with Other Enemies
        for (auto eo : enemyList1)
        {
            if (eo == e) // If we are colliding with ourselves, stop doing that
                continue;
            // If colliding with another enemy, stop enemy
            if (CalculateCollisionsBetween(e,eo) || CalculateCollisionsBetween(e,player1))
            {
                e->Move(-e->GetVelocity());
            }
        }

        // Enemy and Wall Collision
        for (auto walle : wall2)
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
        else {
            for (auto e : enemyList1)
            {
                if (CalculateCollisionsBetween(e, mel))
                {
                    e->Hurt(temp->GetDamage());
                }
            }
        }
    }
}