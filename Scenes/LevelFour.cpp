#include "LevelFour.h"
#include "Door.hpp"
#include "Player.hpp"
#include "Skeleton.hpp"
#include "DeadSoul.hpp"
#include "Wall.hpp"

Physical* wall2[2];
Door* toNextLevel1;
Player* player1;
Actor* enemies1[5];
DeadSoul* speaker1;

void LevelFour::LoadScene()
{
    SetBG("SceneBG/stage_4.png", V2(1920, 1080));
    toNextLevel1 = new Door;
    toNextLevel1->Redirect(LEVELFIVE);
    toNextLevel1->SetPosition(1200, 500);

    player1 = new Player;
    player1->SetPosition(100, 350);

    enemies1[0] = new Skeleton;
    enemies1[0]->SetPosition(850, 250);
    enemies1[1] = new Skeleton;
    enemies1[1]->SetPosition(950, 350);
    enemies1[2] = new Skeleton;
    enemies1[2]->SetPosition(1150, 600);
    enemies1[3] = new Skeleton;
    enemies1[3]->SetPosition(1150, 200);
    enemies1[4] = new Skeleton;
    enemies1[4]->SetPosition(900, 300);

    wall2[0] = new Wall;
    wall2[0]->SetCollisionSize(V2(650, 1000));
    wall2[0]->SetPosition(840, 780);
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
        std::cout << i->GetPosition() << std::endl;
    }
    AddPhysical(speaker1);
}