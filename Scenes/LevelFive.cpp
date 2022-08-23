#pragma once
#include "LevelFive.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Dragon.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"

Door* toNextLevel5;
Player* player5;
Actor* enemies5[3];
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
    enemies5[0]->SetPosition(480, 150);
    enemies5[1] = new Dragon;
    enemies5[1]->SetPosition(1150, 150);
    enemies5[2] = new Dragon;
    enemies5[2]->SetPosition(750, 500);

    speaker5 = new DeadSoul("TEST MESSAGE I WANT TO DIE");
    speaker5->SetPosition(300, 350);

    AddPhysical(player5);
    AddPhysical(toNextLevel5);
    for (auto i : enemies5)
    {
        AddPhysical(i);
        std::cout << i->GetPosition() << std::endl;
    }
    AddPhysical(speaker5);
}

void LevelFive::SceneUpdate()
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

void LevelFive::Collision()
{
    if (CalculateCollisionBorder(player5))
        player5->Move(-player5->GetVelocity());
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