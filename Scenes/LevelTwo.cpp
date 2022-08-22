#include "LevelTwo.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Skeleton.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"

Door* toNextLevel1;
Player* player1;
Actor* enemies1[3];
DeadSoul* speaker1;

void LevelTwo::LoadScene()
{
    SetBG("SceneBG/stage_2.png", V2(1920, 1080));
    toNextLevel1 = new Door;
    toNextLevel1->Redirect(MAINMENU);
    toNextLevel1->SetPosition(1000, 500);

    player1 = new Player;
    player1->SetPosition(100, 350);

    enemies1[0] = new Skeleton;
    enemies1[0]->SetPosition(480, 150);
    enemies1[1] = new Skeleton;
    enemies1[1]->SetPosition(1150, 150);
    enemies1[2] = new Skeleton;
    enemies1[2]->SetPosition(750, 500);

    speaker1 = new DeadSoul("TEST MESSAGE I WANT TO DIE");
    speaker1->SetPosition(300, 350);
    
    AddPhysical(player1);
    AddPhysical(toNextLevel1);
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
        if (enemy->GetHealth() <= 0)
            Kill(enemy);
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
}

void LevelTwo::Collision()
{
    if (CalculateCollisionBorder(player1))
        player1->Move(-player1->GetVelocity());
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