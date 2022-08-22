#include "LevelTwo.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Slime.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"

Door* toNextLevel;
Player* player;
Actor* enemies[3];
DeadSoul* speaker;

void LevelTwo::LoadScene()
{
    SetBG("SceneBG/stage_2.png", V2(1920, 1080));
    toNextLevel = new Door;
    toNextLevel->Redirect(LEVELONE);
    toNextLevel->SetPosition(1000, 500);

    player = new Player;
    player->SetPosition(100, 350);

    enemies[0] = new Slime;
    enemies[0]->SetPosition(480, 150);
    enemies[1] = new Slime;
    enemies[1]->SetPosition(1150, 150);
    enemies[2] = new Slime;
    enemies[2]->SetPosition(750, 500);

    speaker = new DeadSoul("TEST MESSAGE I WANT TO DIE");
    speaker->SetPosition(300, 350);
    speaker->SetOrientation(DeadSoul::DOWN);

    AddPhysical(player);
    AddPhysical(toNextLevel);
    for (auto i : enemies)
    {
        AddPhysical(i);
        std::cout << i->GetPosition() << std::endl;
    }
    AddPhysical(speaker);