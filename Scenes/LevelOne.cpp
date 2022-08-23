#include "LevelOne.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Slime.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"

Door* toNextLevel;
Player* player;
Actor* enemies[3];
DeadSoul* speaker;

void LevelOne::LoadScene()
{
    SetBG("SceneBG/stage_1.png",V2(1920,1080));
    toNextLevel = new Door;
    toNextLevel->Redirect(MAINMENU);
    toNextLevel->SetPosition(1000,500);

    player = new Player;
    player->SetPosition(100,350);

    enemies[0] = new Slime;
    enemies[0]->SetPosition(480,150);
    enemies[1] = new Slime;
    enemies[1]->SetPosition(1150,150);
    enemies[2] = new Slime;
    enemies[2]->SetPosition(750,500);

    speaker = new DeadSoul("TEST MESSAGE I WANT TO DIE");
    speaker->SetPosition(300,350);
    speaker->SetOrientation(DeadSoul::DOWN);

    AddPhysical(player);
    AddPhysical(toNextLevel);
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
        if (enemy->GetHealth() <= 0)
            Kill(enemy);
    }
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
            enemy->LookAt(player);
            if (CalculateCollisionsBetween(arrow, enemy))
            {
                enemy->Hurt(arrow->GetDamage());
                Kill(arrow);
                std::cout << enemy->GetHealth() << std::endl;
            }
        }
    }
}
