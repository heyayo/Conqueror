#include "LevelTwo.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Goblin.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Physical.hpp"
#include "Wall.hpp"

Physical* wall1[2];
Door* toNextLevel1;
Player* player1;
Actor* enemies1[5];
DeadSoul* speaker1;

void LevelTwo::LoadScene()
{
    SetBG("SceneBG/stage_2.png", V2(1920, 1080));
    toNextLevel1 = new Door;
    toNextLevel1->Redirect(MAINMENU);
    toNextLevel1->SetPosition(1250, 500);

    player1 = new Player;
    player1->SetPosition(100, 350);

    enemies1[0] = new Goblin;
    enemies1[0]->SetPosition(480, 150);
    enemies1[1] = new Goblin;
    enemies1[1]->SetPosition(1150, 150);
    enemies1[2] = new Goblin;
    enemies1[2]->SetPosition(750, 500);
    enemies1[3] = new Goblin;
    enemies1[3]->SetPosition(550, 200);
    enemies1[4] = new Goblin;
    enemies1[4]->SetPosition(900, 300);

    wall1[0] = new Wall;
    wall1[0]->SetCollisionSize(V2(650,1000));
    wall1[0]->SetPosition(840,780);
    wall1[0]->Init(BLACK, V2(350, 580));
    wall1[1] = new Wall;
    wall1[1]->SetCollisionSize(V2(180, 240));
    wall1[1]->SetPosition(840, 120);
    wall1[1]->Init(GREEN, V2(330, 220));
    speaker1 = new DeadSoul("TEST MESSAGE I WANT TO DIE");
    speaker1->SetPosition(300, 350);
    
    AddPhysical(player1);
    AddPhysical(toNextLevel1);
    AddPhysical(wall1[0]);
    AddPhysical(wall1[1]);
    for (auto i : enemies1)
    {
        AddPhysical(i);
        std::cout << i->GetPosition() << std::endl;
    }
    AddPhysical(speaker1);
}

void LevelTwo::SceneUpdate()
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

void LevelTwo::Collision()
{
    if (CalculateCollisionBorder(player1))
    {
        player1->Move(-player1->GetVelocity());
    }
    if (CalculateCollisionsBetween(player1, wall1[0]))
    {
        player1->Move(-player1->GetVelocity());
    }
    /*for (int i = 0; i < 6; i++)
    {
        if (CalculateCollisionsBetween(enemies1[i], wall1[0]))
        {
            enemies1[i]->Move(-enemies1[i]->GetVelocity());
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if (CalculateCollisionsBetween(enemies1[i], wall1[1]))
        {
            enemies1[i]->Move(-enemies1[i]->GetVelocity());
        }
    }*/
    if (CalculateCollisionsBetween(player1, wall1[1]))
    {
        player1->Move(-player1->GetVelocity());
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