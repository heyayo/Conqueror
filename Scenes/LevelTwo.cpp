#include "LevelTwo.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Goblin.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include <thread>
#include "timer.h"

// Create pointers to scene entities
Door* toNextLevel1;
Player* player1;
Actor* enemies1[3];
DeadSoul* speaker1;

void LevelTwo::LoadScene()
{
    // Set the Scene Background
    SetBG("SceneBG/stage_2.png", V2(1920, 1080));

    // Create Door, Redirect door, Set Position
    toNextLevel1 = new Door;
    toNextLevel1->Redirect(LEVELONE);
    toNextLevel1->SetPosition(1000, 500);

    // Create Player, Set Position
    player1 = new Player;
    player1->SetPosition(100, 350);

    // Create Enemies and Set Positions
    enemies1[0] = new Goblin;
    enemies1[0]->SetPosition(480, 150);
    enemies1[1] = new Goblin;
    enemies1[1]->SetPosition(1150, 150);
    enemies1[2] = new Goblin;
    enemies1[2]->SetPosition(750, 500);

    // Load Messages to Display on Scroll
    std::string m[6];
    m[0] = "RIDE WIFE";
    m[1] = "LIFE GOOD";
    m[2] = "WIFE FIGHT BACK";
    m[3] = "KILL WIFE";
    m[4] = "WIFE GONE";
    m[5] = "REGRET";
    // Create the Dead Soul that displays the scroll
    speaker1 = new DeadSoul(m,6); // ( List of Messages, Message Count )
    // Set Position of Dead Soul
    speaker1->SetPosition(300, 350);

    // Spawn Entities into World
    AddPhysical(player1);
    AddPhysical(toNextLevel1);
    for (auto i : enemies1)
    {
        AddPhysical(i);
    }
    AddPhysical(speaker1);
}

void LevelTwo::SceneUpdate()
{
    // Tick Enemy AI and Kill if Health Depleted
    std::vector<Actor*> enemylist = GetActorsByGroup("ENEMY");
    for (auto enemy : enemylist)
    {
        Enemy* enemyconv = dynamic_cast<Enemy*>(enemy);
        enemyconv->Act();
        if (enemy->GetHealth() <= 0)
            Kill(enemy);
    }

    // DEBUG OPTION, MOUSE LEFT PRINTS OUT LOCATION IN SPACE
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
    }
}

void LevelTwo::Collision()
{
    // Player Collision With Border
    if (CalculateCollisionBorder(player1))
        player1->Move(-player1->GetVelocity());

    // Enemy Collision With Arrows
    std::vector<Actor*> arrows = GetActorsByGroup("PROJECTILE");
    std::vector<Actor*> enemyList = GetActorsByGroup("ENEMY");

    // Enemy Collisions
    for (auto e : enemies1)
    {
        for (auto arrow : arrows)
        {
            // Kill Arrow on Border Collision
            if (CalculateCollisionBorder(arrow))
                Kill(arrow);
            // Kill Arrow and Hurt Enemy on Enemy Collision
            if (CalculateCollisionsBetween(arrow, e))
            {
                e->Hurt(arrow->GetDamage());
                Kill(arrow);
            }
        }
        // Collision with Other Enemies
        for (auto eo : enemies1)
        {
            if (eo == e) // If we are colliding with ourselves, stop doing that
                continue;
            // If colliding with another enemy, stop enemy
            if (CalculateCollisionsBetween(e,eo) && CalculateCollisionsBetween(e,player1))
            {
                e->Move(-e->GetVelocity());
            }
        }
    }
}