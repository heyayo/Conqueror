#include "LevelFour.h"
#include "Door.hpp"
#include "Player.hpp"
#include "Skeleton.hpp"
#include "DeadSoul.hpp"
#include "Wall.hpp"

Physical* wall4[2];
Door* toNextLevel4;
Player* player4;
Actor* enemies4[5];
DeadSoul* speaker4;

void LevelFour::LoadScene()
{
    SetBG("SceneBG/stage_4.png", V2(1920, 1080));
    toNextLevel4 = new Door;
    toNextLevel4->Redirect(LEVELFIVE);
    toNextLevel4->SetPosition(1200, 500);

    player4 = new Player;
    player4->SetPosition(100, 350);

    enemies4[0] = new Skeleton;
    enemies4[0]->SetPosition(850, 250);
    enemies4[1] = new Skeleton;
    enemies4[1]->SetPosition(950, 350);
    enemies4[2] = new Skeleton;
    enemies4[2]->SetPosition(1150, 600);
    enemies4[3] = new Skeleton;
    enemies4[3]->SetPosition(1150, 200);
    enemies4[4] = new Skeleton;
    enemies4[4]->SetPosition(900, 300);

    wall4[0] = new Wall;
    wall4[0]->SetCollisionSize(V2(650, 1000));
    wall4[0]->SetPosition(840, 780);
    wall4[0]->Init(BLACK, V2(350, 580));
    wall4[1] = new Wall;
    wall4[1]->SetCollisionSize(V2(180, 240));
    wall4[1]->SetPosition(840, 120);
    wall4[1]->Init(GREEN, V2(330, 220));
    std::string m[6];
    m[0] = "RIDE WIFE";
    m[1] = "LIFE GOOD";
    m[2] = "WIFE FIGHT BACK";
    m[3] = "KILL WIFE";
    m[4] = "WIFE GONE";
    m[5] = "REGRET";
    speaker4 = new DeadSoul(m, 6);
    speaker4->SetPosition(300, 350);

    AddPhysical(player4);
    AddPhysical(toNextLevel4);
    AddPhysical(wall4[0]);
    AddPhysical(wall4[1]);
    for (auto i : enemies4)
    {
        AddPhysical(i);
        std::cout << i->GetPosition() << std::endl;
    }
    AddPhysical(speaker4);
}