#include "LevelThree.h"
#include "Door.hpp"
#include "Player.hpp"
#include "Skeleton.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Melee.hpp"
#include "Physical.hpp"
#include "Wall.hpp"
#include "Bar.hpp"
#include "TextBox.hpp"
#include <string>
Physical* wall3[2];
Door* toNextLevel3;
Player* player3;
Actor* enemies3[5];
Bar* ebars3[5];
DeadSoul* speaker3;
Bar* pHP3;
TextBox* Status3;
std::string st3[2];

bool enemiesAlive3 = true;
void LevelThree::LoadScene()
{
    enemiesAlive3 = true;
    SaveState temp = LoadSave();
    temp.currentLevel = LEVELTHREE;
    CreateSave(temp);

    SetBG("SceneBG/stage_3.png", V2(1920, 1080));
    toNextLevel3 = new Door;
    toNextLevel3->Redirect(LEVELMID1);
    toNextLevel3->SetPosition(1500, 500);

    player3 = new Player;
    player3->SetPosition(100, 350);
    pHP3 = new Bar(player3->GetHealthPtr(),
                  temp.health,
                  PURPLE,
                  GetScreenWidthDeltad(),
                  25);
    V2 pBarOffset(0,GetScreenHeightDeltad()/2);
    pHP3->SetPosition(GetScreenCenter() + pBarOffset);
    AddUI(pHP3);

    enemies3[0] = new Skeleton;
    enemies3[0]->SetPosition(1100, 250);
    enemies3[1] = new Skeleton;
    enemies3[1]->SetPosition(100, 350);
    enemies3[2] = new Skeleton;
    enemies3[2]->SetPosition(1300, 400);
    enemies3[3] = new Skeleton;
    enemies3[3]->SetPosition(1130, 200);
    enemies3[4] = new Skeleton;
    enemies3[4]->SetPosition(1120, 300);
    for (int i = 0; i < 5; i++)
    {
        ebars3[i] = new Bar(enemies3[i]->GetHealthPtr(),
                            120,
                            GREEN,
                            enemies3[i]->GetSize().x,
                            5);
        AddUI(ebars3[i]);
    }

    wall3[0] = new Wall;
    wall3[0]->SetCollisionSize(V2(650, 1000));
    wall3[0]->SetPosition(1070, 740);
    wall3[0]->Init({0,0,0,0}, V2(240, 750));
    wall3[1] = new Wall;
    wall3[1]->SetCollisionSize(V2(180, 240));
    wall3[1]->SetPosition(400, 930);
    wall3[1]->Init({0,0,0,0}, V2(1100, 220));
    std::string m[6];
    m[0] = "RIDE WIFE";
    m[1] = "LIFE GOOD";
    m[2] = "WIFE FIGHT BACK";
    m[3] = "KILL WIFE";
    m[4] = "WIFE GONE";
    m[5] = "REGRET";
    speaker3 = new DeadSoul(m, 6);
    speaker3->SetPosition(300, 350);

    st3[0] = "Journals Collected";
    st3[1] = std::to_string(temp.JournalCount);
    Status3 = new TextBox(st3,2);
    Status3->SetPosition(GetScreenCenter());
    Status3->SetFontSize(100);
    Status3->SetPadding(V2(100,100));
    Status3->SetAlignment(TextBox::CENTER);
    AddUI(Status3);

    AddPhysical(player3);
    AddPhysical(wall3[0]);
    AddPhysical(wall3[1]);
    for (auto i : enemies3)
    {
        AddPhysical(i);
    }
    AddPhysical(speaker3);
}

void LevelThree::SceneUpdate()
{
    if (GetActorsByGroup("ENEMY").size() == 0 && enemiesAlive3)
    {
        enemiesAlive3 = false;
        AddPhysical(toNextLevel3);
    }
    if (player3->GetHealth() <= 0)
    {
        LoadSceneByEnum(LEVELTHREE);
    }
    Status3->SetVisibility(IsKeyDown(KEY_I));
    for (int i = 0; i < 5; i++)
    {
        if (enemies3[i]->GetHealth() <= 0)
        {
            Kill(enemies3[i]);
            RemoveUI(ebars3[i]);
            continue;
        }
        V2 barOffset(0,enemies3[i]->GetSize().y/2);
        ebars3[i]->SetPosition(enemies3[i]->GetPosition()+barOffset);
    }
}

void LevelThree::Collision()
{
    // Player Press e to Collect Journal
    if (CalculateCollisionsBetween(player3,speaker3) && IsKeyPressed(KEY_E))
    {
        player3->TickJournalCount();
        Kill(speaker3);
        RemoveUI(GetUIElementByName("SPEAKERBOX"));
        st3[1] = std::to_string(player3->GetJournalCount());
        Status3->SetTexts(st3,2);
    }

    for (auto walls : wall3)
        if (CalculateCollisionsBetween(player3, walls))
            player3->Move(-player3->GetVelocity());

    // Player Collision With Border
    if (CalculateCollisionBorder(player3))
        player3->Move(-player3->GetVelocity());

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
                for (auto walle : wall3)
                {
                    if (CalculateCollisionsBetween(walle, arrow))
                        Kill(arrow);
                }
            }
        }
        // Collision with Other Enemies
        for (auto eo : enemyList1)
        {
            if (eo == e) // If we are colliding with ourselves, stop doing that
                continue;
            // If colliding with another enemy, stop enemy
            if (CalculateCollisionsBetween(e, eo) || CalculateCollisionsBetween(e, player3))
            {
                e->Move(-e->GetVelocity());
            }
        }

        // Enemy and Wall Collision
        for (auto walle : wall3)
        {
            if (CalculateCollisionsBetween(walle, e))
            {
                e->Move(-e->GetVelocity());
            }
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