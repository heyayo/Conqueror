#include "LevelFive.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Dragon.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Melee.hpp"
#include "Wall.hpp"
#include "Bar.hpp"
#include "TextBox.hpp"

Physical* wall5[2];
Door* toNextLevel5;
Player* player5;
Actor* enemies5[1];
Bar* bossbar;
DeadSoul* speaker5;
Bar* pHP5;
TextBox* Status5;
std::string st5[2];

void LevelFive::LoadScene()
{
    SaveState temp = LoadSave();
    temp.currentLevel = LEVELFIVE;
    CreateSave(temp);

    SetBG("SceneBG/stage Final.png", V2(1920, 1080));
    toNextLevel5 = new Door;
    toNextLevel5->Redirect(MAINMENU);
    toNextLevel5->SetPosition(1000, 500);

    player5 = new Player;
    player5->SetPosition(100, 350);
    pHP5 = new Bar(player5->GetHealthPtr(),
                  temp.health,
                  PURPLE,
                  GetScreenWidthDeltad(),
                  25);
    V2 pBarOffset(0,GetScreenHeightDeltad()/2);
    pHP5->SetPosition(GetScreenCenter() + pBarOffset);
    AddUI(pHP5);

    enemies5[0] = new Dragon;
    enemies5[0]->SetPosition(1300, 540);
    bossbar = new Bar(enemies5[0]->GetHealthPtr(),
                      100,
                      GOLD,
                      enemies5[0]->GetSize().x,
                      10);
    AddUI(bossbar);

    wall5[0] = new Wall;
    wall5[0]->SetCollisionSize(V2(550, 300));
    wall5[0]->SetPosition(220, 980);
    wall5[0]->Init(RED, V2(460, 230));

    wall5[1] = new Wall;
    wall5[1]->SetCollisionSize(V2(550, 300));
    wall5[1]->SetPosition(220, 90);
    wall5[1]->Init(GREEN, V2(460, 240));

    std::string m[6];
    m[0] = "RIDE WIFE";
    m[1] = "LIFE GOOD";
    m[2] = "WIFE FIGHT BACK";
    m[3] = "KILL WIFE";
    m[4] = "WIFE GONE";
    m[5] = "REGRET";
    speaker5 = new DeadSoul(m,6);
    speaker5->SetPosition(300, 350);

    st5[0] = "Journals Collected";
    st5[1] = std::to_string(temp.JournalCount);
    Status5 = new TextBox(st5,2);
    Status5->SetPosition(GetScreenCenter());
    Status5->SetFontSize(100);
    Status5->SetPadding(V2(100,100));
    Status5->SetAlignment(TextBox::CENTER);
    AddUI(Status5);

    AddPhysical(player5);
    AddPhysical(wall5[0]);
    AddPhysical(wall5[1]);
    for (auto i : enemies5)
    {
        AddPhysical(i);
    }
    AddPhysical(speaker5);
}

bool bossAlive = true;
void LevelFive::SceneUpdate()
{
    if (player5->GetHealth() <= 0)
    {
        LoadSceneByEnum(LEVELFIVE);
    }
    Status5->SetVisibility(IsKeyDown(KEY_I));
    if (enemies5[0]->GetHealth() <= 0 && bossAlive)
    {
        Kill(enemies5[0]);
        RemoveUI(bossbar);
        AddPhysical(toNextLevel5);
        bossAlive = false;
    }
    V2 barOffset(0,enemies5[0]->GetSize().y/2);
    bossbar->SetPosition(enemies5[0]->GetPosition()+barOffset);
}

void LevelFive::Collision()
{
    // Player Press e to Collect Journal
    if (CalculateCollisionsBetween(player5,speaker5) && IsKeyPressed(KEY_E))
    {
        player5->TickJournalCount();
        Kill(speaker5);
        RemoveUI(GetUIElementByName("SPEAKERBOX"));
        st5[1] = std::to_string(player5->GetJournalCount());
        Status5->SetTexts(st5,2);
    }

    for (auto walls : wall5)
        if (CalculateCollisionsBetween(player5,walls))
            player5->Move(-player5->GetVelocity());

    // Player Collision With Border
    if (CalculateCollisionBorder(player5))
        player5->Move(-player5->GetVelocity());

    // Enemy Collision With Arrows
    std::vector<Actor*> arrows = GetActorsByGroup("PROJECTILE");
    std::vector<Actor*> EnemyFireballs = GetActorsByGroup("ENEMYPROJECTILE");
    std::vector<Actor*> enemyList1 = GetActorsByGroup("ENEMY");

    // Enemy Collisions
    for (auto e : enemyList1)
    {
        Dragon* enemyconv = dynamic_cast<Dragon*>(e);
        enemyconv->Act();
        enemyconv->LookAt(player5);
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
                for (auto walle : wall5)
                {
                    if (CalculateCollisionsBetween(walle, arrow))
                        Kill(arrow);
                }

            }
        }
        for (auto EnemyFireball : EnemyFireballs)
        {
            // Kill EnemyFireball on Border Collision
            if (CalculateCollisionBorder(EnemyFireball))
            {
                Kill(EnemyFireball);
            }
            // Kill EnemyFireball and Hurt Enemy on Enemy Collision
            else if (CalculateCollisionsBetween(EnemyFireball, player5))
            {
                player5->Hurt(EnemyFireball->GetDamage());
                Kill(EnemyFireball);
            }
        }
        // Collision with Other Enemies
        for (auto eo : enemyList1)
        {
            if (eo == e) // If we are colliding with ourselves, stop doing that
                continue;
            // If colliding with another enemy, stop enemy
            if (CalculateCollisionsBetween(e, eo) || CalculateCollisionsBetween(e, player5))
            {
                e->Move(-e->GetVelocity());
            }
        }
        // Enemy and Wall Collision
        for (auto walle : wall5)
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