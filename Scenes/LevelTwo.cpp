#include "LevelTwo.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Goblin.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Melee.hpp"
#include "Physical.hpp"
#include "Wall.hpp"
#include "Bar.hpp"
#include "TextBox.hpp"
#include <string>

Physical* wall2[2];
Door* toNextLevel1;
Player* player1;
Actor* enemies1[5];
DeadSoul* speaker1;
Bar* ebars2[5];
Bar* pHP2;
TextBox* Status2;
std::string st2[2];

bool enemiesAlive2 = true;
void LevelTwo::LoadScene()
{
    enemiesAlive2 = true;
    SaveState temp = LoadSave();
    temp.currentLevel = LEVELONE;
    CreateSave(temp);

    SetBG("SceneBG/stage_2.png", V2(1920, 1080));
    toNextLevel1 = new Door;
    toNextLevel1->Redirect(LEVELTHREE);
    toNextLevel1->SetPosition(1700, 500);

    player1 = new Player;
    player1->SetPosition(100, 350);
    pHP2 = new Bar(player1->GetHealthPtr(),
                  temp.health,
                  PURPLE,
                  GetScreenWidthDeltad(),
                  25);
    V2 pBarOffset(0,GetScreenHeightDeltad()/2);
    pHP2->SetPosition(GetScreenCenter() + pBarOffset);
    AddUI(pHP2);

    enemies1[0] = new Goblin;
    enemies1[0]->SetPosition(850, 250);
    enemies1[1] = new Goblin;
    enemies1[1]->SetPosition(950, 350);
    enemies1[2] = new Goblin;
    enemies1[2]->SetPosition(1150, 600);
    enemies1[3] = new Goblin;
    enemies1[3]->SetPosition(1150, 200);
    enemies1[4] = new Goblin;
    enemies1[4]->SetPosition(900, 300);
    for (int i = 0; i < 5; i++)
    {
        ebars2[i] = new Bar(enemies1[i]->GetHealthPtr(),
                                    20,
                                    GREEN,
                                    enemies1[i]->GetSize().x,
                                    5);
        AddUI(ebars2[i]);
    }

    wall2[0] = new Wall;
    wall2[0]->SetCollisionSize(V2(650,1000));
    wall2[0]->SetPosition(840,780);
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

    st2[0] = "Journals Collected";
    st2[1] = std::to_string(temp.JournalCount);
    Status2 = new TextBox(st2,2);
    Status2->SetPosition(GetScreenCenter());
    Status2->SetFontSize(100);
    Status2->SetPadding(V2(100,100));
    Status2->SetAlignment(TextBox::CENTER);
    AddUI(Status2);

    AddPhysical(player1);
    AddPhysical(wall2[0]);
    AddPhysical(wall2[1]);
    for (auto i : enemies1)
    {
        AddPhysical(i);
    }
    AddPhysical(speaker1);
}

void LevelTwo::SceneUpdate()
{
    if (GetActorsByGroup("ENEMY").size() == 0 && enemiesAlive2)
    {
        enemiesAlive2 = false;
        AddPhysical(toNextLevel1);
    }
    if (player1->GetHealth() <= 0)
    {
        LoadSceneByEnum(LEVELTWO);
    }
    Status2->SetVisibility(IsKeyDown(KEY_I));
    for (int i = 0; i < 5; i++)
    {
        if (enemies1[i]->GetHealth() <= 0)
        {
            Kill(enemies1[i]);
            RemoveUI(ebars2[i]);
            continue;
        }
        V2 barOffset(0,enemies1[i]->GetSize().y/2);
        ebars2[i]->SetPosition(enemies1[i]->GetPosition()+barOffset);
    }
}

void LevelTwo::Collision()
{
    // Player Press e to Collect Journal
    if (CalculateCollisionsBetween(player1,speaker1) && IsKeyPressed(KEY_E))
    {
        player1->TickJournalCount();
        Kill(speaker1);
        RemoveUI(GetUIElementByName("SPEAKERBOX"));
        st2[1] = std::to_string(player1->GetJournalCount());
        Status2->SetTexts(st2,2);
    }

    for (auto walls : wall2)
        if (CalculateCollisionsBetween(player1,walls))
            player1->Move(-player1->GetVelocity());

    // Player Collision With Border
    if (CalculateCollisionBorder(player1))
        player1->Move(-player1->GetVelocity());

    // Enemy Collision With Arrows
    std::vector<Actor*> arrows = GetActorsByGroup("PROJECTILE");
    std::vector<Actor*> enemyList1 = GetActorsByGroup("ENEMY");

    // Enemy Collisions
    for (auto e : enemyList1)
    {
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
                for (auto walle : wall2)
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
            if (CalculateCollisionsBetween(e,eo) || CalculateCollisionsBetween(e,player1))
            {
                e->Move(-e->GetVelocity());
            }
        }

        // Enemy and Wall Collision
        for (auto walle : wall2)
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