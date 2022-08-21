#include "LevelOne.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Slime.hpp"
#include "Maths.hpp"

Door* toNextLevel;
Player* player;
Actor* enemies[3];

void LevelOne::LoadScene()
{
    SetBG("SceneBG/stage_1.png",V2(1920,1080));
    toNextLevel = new Door;
    toNextLevel->Redirect(MAINMENU);
    toNextLevel->SetPosition(1800,500);

    player = new Player;
    player->SetPosition(100,350);

    enemies[0] = new Slime;
    enemies[0]->SetPosition(480,150);
    enemies[1] = new Slime;
    enemies[1]->SetPosition(1150,150);
    enemies[2] = new Slime;
    enemies[2]->SetPosition(750,500);

    AddPhysical(player);
    AddPhysical(toNextLevel);
    for (auto i : enemies)
    {
        AddPhysical(i);
        std::cout << i->GetPosition() << std::endl;
    }
}

void LevelOne::SceneUpdate()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
}

void LevelOne::Collision()
{
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
            if (CalculateCollisionsBetween(arrow, enemy))
            {
                enemy->Hurt(arrow->GetDamage());
                std::cout << enemy->GetHealth() << std::endl;
            }
        }
    }
}