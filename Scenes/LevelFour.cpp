#include "LevelFour.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Demon.h"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Wall.hpp"
#include "Melee.hpp"
#include "Physical.hpp"
#include "Bar.hpp"
#include "TextBox.hpp"
#include <string>

Physical* wall4[2];
Door* toNextLevel4;
Player* player4;
Actor* enemies4[5];
Bar* ebars4[5];
DeadSoul* speaker4;
Bar* pHP4;
TextBox* Status4;
std::string st4[2];

bool enemiesAlive4 = true;
void LevelFour::LoadScene()
{
    enemiesAlive4 = true;
    SaveState temp = LoadSave();
    temp.currentLevel = LEVELFOUR;
    CreateSave(temp);

    SetBG("SceneBG/stage_4.png", V2(1920, 1080));
    toNextLevel4 = new Door;
    toNextLevel4->Redirect(LEVELMID1);
    toNextLevel4->SetPosition(1200, 500);

    player4 = new Player;
    player4->SetPosition(0, 350);
    pHP4 = new Bar(player4->GetHealthPtr(),
                  temp.health,
                  PURPLE,
                  GetScreenWidthDeltad(),
                  25);
    V2 pBarOffset(0,GetScreenHeightDeltad()/2);
    pHP4->SetPosition(GetScreenCenter() + pBarOffset);
    AddUI(pHP4);

    enemies4[0] = new Demon;
    enemies4[0]->SetPosition(850, 250);
    enemies4[1] = new Demon;
    enemies4[1]->SetPosition(950, 350);
    enemies4[2] = new Demon;
    enemies4[2]->SetPosition(1150, 600);
    enemies4[3] = new Demon;
    enemies4[3]->SetPosition(1150, 200);
    enemies4[4] = new Demon;
    enemies4[4]->SetPosition(900, 300);
    for (int i = 0; i < 5; i++)
    {
        ebars4[i] = new Bar(enemies4[i]->GetHealthPtr(),
                            200,
                            GREEN,
                            enemies4[i]->GetSize().x,
                            5);
        AddUI(ebars4[i]);
    }

    wall4[0] = new Wall;
    wall4[0]->SetCollisionSize(V2(150, 500));
    wall4[0]->SetPosition(600, 830);
    wall4[0]->Init({0,0,0,0}, V2(150, 580));
    wall4[1] = new Wall;
    wall4[1]->SetCollisionSize(V2(150, 230));
    wall4[1]->SetPosition(480, 480);
    wall4[1]->Init({0,0,0,0}, V2(400, 150));
    std::string m[5];
    m[0] = "The deepest part of the cave...";
    m[1] = "It is so hot in here...who are those";
    m[2] = "people with horns? And what";
    m[3] = "is that charred thing that ";
    m[4] = "they are dragging off with them?";
    speaker4 = new DeadSoul(m, 5);
    speaker4->SetPosition(1700, 850);

    st4[0] = "Journals Collected";
    st4[1] = std::to_string(temp.JournalCount);
    Status4 = new TextBox(st4,2);
    Status4->SetPosition(GetScreenCenter());
    Status4->SetFontSize(100);
    Status4->SetPadding(V2(100,100));
    Status4->SetAlignment(TextBox::CENTER);
    AddUI(Status4);

    AddPhysical(player4);
    AddPhysical(wall4[0]);
    AddPhysical(wall4[1]);
    for (auto i : enemies4)
    {
        AddPhysical(i);
    }
    AddPhysical(speaker4);
}

void LevelFour::SceneUpdate()
{
    if (GetActorsByGroup("ENEMY").size() == 0 && enemiesAlive4)
    {
        enemiesAlive4 = false;
        AddPhysical(toNextLevel4);
    }
    if (player4->GetHealth() <= 0)
    {
        LoadSceneByEnum(LEVELFOUR);
    }
    Status4->SetVisibility(IsKeyDown(KEY_I));
    for (int i = 0; i < 5; i++)
    {
        if (enemies4[i]->GetHealth() <= 0)
        {
            Kill(enemies4[i]);
            RemoveUI(ebars4[i]);
            continue;
        }
        V2 barOffset(0,enemies4[i]->GetSize().y/2);
        ebars4[i]->SetPosition(enemies4[i]->GetPosition()+barOffset);
    }
}

void LevelFour::Collision()
{
    // Player Press e to Collect Journal
    if (CalculateCollisionsBetween(player4,speaker4) && IsKeyPressed(KEY_E))
    {
        player4->TickJournalCount();
        Kill(speaker4);
        RemoveUI(GetUIElementByName("SPEAKERBOX"));
        st4[1] = std::to_string(player4->GetJournalCount());
        Status4->SetTexts(st4,2);
    }

    for (auto walls : wall4)
        if (CalculateCollisionsBetween(player4, walls))
            player4->Move(-player4->GetVelocity());

    // Player Collision With Border
    if (CalculateCollisionBorder(player4))
        player4->Move(-player4->GetVelocity());

    // Enemy Collision With Arrows
    std::vector<Actor*> arrows = GetActorsByGroup("PROJECTILE");
    std::vector<Actor*> enemyList1 = GetActorsByGroup("ENEMY");

    // Enemy Collisions
    for (auto e : enemyList1)
    {
        if (e == nullptr)
            continue;
        Enemy* enemyconv = dynamic_cast<Enemy*>(e);
        enemyconv->Act();
        for (auto arrow : arrows)
        {
            // Kill Arrow on Border Collision
            if (CalculateCollisionBorder(arrow))
            {
                Kill(arrow);
            }
            // Kill Arrow and Hurt Enemy on Enemy Collision
            else if (CalculateCollisionsBetween(arrow, e))
            {
                e->Hurt(arrow->GetDamage());
                Kill(arrow);
            }
            else {
                for (auto walle : wall4)
                {
                    if (CalculateCollisionsBetween(walle, arrow))
                        Kill(arrow);
                }
            }

        }

        // Collision with Player
        if (CalculateCollisionsBetween(e, player4))
        {
            e->Move(-e->GetVelocity());
        }

        // Enemy and Wall Collision
        for (auto walle : wall4)
        {
            if (CalculateCollisionsBetween(walle, e))
                e->Move(-e->GetVelocity());
        }
    }

    // Melee Collision Checking
    std::vector<Physical*> melee = GetPhysicsByGroup("MELEE");
    for (auto mel : melee)
    {
        Melee* temp = static_cast<Melee*>(mel);
        if (temp->cooldown >= temp->maxCooldown)
            Kill(mel);
        else {
            for (auto e : enemyList1)
            {
                if (CalculateCollisionsBetween(e, mel))
                {
                    e->Hurt(temp->GetDamage());
                }
            }
        }
    }
}