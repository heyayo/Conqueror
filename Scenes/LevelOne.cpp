#include "LevelOne.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Slime.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "LevelTwo.hpp"
#include "Wall.hpp"

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

    speaker = new DeadSoul("TEST MESSAGE I WANT TO DIE");
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
    std::vector<Actor*> enemylist = GetActorsByGroup("ENEMY");
    for (auto enemy : enemylist)
    {
        enemy->LookAt(player);
        dynamic_cast<Enemy*>(enemy)->Act();
        if (enemy->GetHealth() <= 0)
        {
            Kill(enemy);
            continue;
        }
        dynamic_cast<Enemy*>(enemy)->Act();
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
}

void LevelOne::Collision()
{
    if (CalculateCollisionBorder(player))
    {
        player->Move(-player->GetVelocity());
    }
    if (CalculateCollisionsBetween(player, wall1[0]))
    {
        player->Move(-player->GetVelocity());
    }
    if (CalculateCollisionsBetween(player, wall1[1]))
    {
        player->Move(-player->GetVelocity());
    }
    if (CalculateCollisionBorder(player))
        player->Move(-player->GetVelocity());
    std::vector<Actor*> arrows = GetActorsByGroup("PROJECTILE");
    std::vector<Actor*> enemyList = GetActorsByGroup("ENEMY");
    for (auto arrow : arrows)
    {
        if (CalculateCollisionBorder(arrow))
            Kill(arrow);
        for (auto enemy : enemyList)
        {
            enemy->LookAt(player);
            if (CalculateCollisionsBetween(arrow, enemy))
            {
                enemy->Hurt(arrow->GetDamage());
                Kill(arrow);
            }
        }
    }
}
