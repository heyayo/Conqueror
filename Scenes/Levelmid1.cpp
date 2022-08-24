#include "Levelmid1.hpp"
#include "Door.hpp"
#include "Player.hpp"
#include "Maths.hpp"
#include "DeadSoul.hpp"
#include "Wall.hpp"
#include "Melee.hpp"
#include "HPcrystal.hpp"

Physical* wallmid1[2];
Door* toNextLevelmid1;
Player* playermid1;
DeadSoul* speakermid1;
HPcrystal* HPcrystal1;

void Levelmid1::LoadScene()
{
    SetBG("SceneBG/stage middle.png", V2(1920, 1080));
    toNextLevelmid1 = new Door;
    toNextLevelmid1->Redirect(LEVELTWO);
    toNextLevelmid1->SetPosition(1500, 500);

    playermid1 = new Player;
    playermid1->SetPosition(100, 350);

    HPcrystal1 = new HPcrystal;
    HPcrystal1->SetPosition(1000, 500);
  
    wallmid1[0] = new Wall;
    wallmid1[0]->SetCollisionSize(V2(350, 1000));
    wallmid1[0]->SetPosition(250, 950);
    wallmid1[0]->Init(RED, V2(550, 300));
    wallmid1[1] = new Wall;
    wallmid1[1]->SetCollisionSize(V2(180, 240));
    wallmid1[1]->SetPosition(250, 120);
    wallmid1[1]->Init(GREEN, V2(550, 300));

    std::string m[6];
    m[0] = "RIDE WIFE";
    m[1] = "LIFE GOOD";
    m[2] = "WIFE FIGHT BACK";
    m[3] = "KILL WIFE";
    m[4] = "WIFE GONE";
    m[5] = "REGRET";
    speakermid1 = new DeadSoul(m, 6);
    speakermid1->SetPosition(1000, 350);

    AddPhysical(playermid1);
    AddPhysical(toNextLevelmid1);
    AddPhysical(wallmid1[0]);
    AddPhysical(wallmid1[1]);
    AddPhysical(HPcrystal1);
}

void Levelmid1::SceneUpdate()
{
    // DEBUG OPTION, MOUSE LEFT PRINTS OUT LOCATION IN SPACE
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        std::cout << Maths::ConvertToV2(GetMousePosition()) << std::endl;
    }
}

void Levelmid1::Collision()
{
    if (CalculateCollisionsBetween(playermid1, HPcrystal1))
    {
        Kill(HPcrystal1);
    }
    for (auto walls : wallmid1)
        if (CalculateCollisionsBetween(playermid1, walls))
            playermid1->Move(-playermid1->GetVelocity());

    // playermid1 Collision With Border
    if (CalculateCollisionBorder(playermid1))
        playermid1->Move(-playermid1->GetVelocity());

    // Enemy Collision With Arrows
    std::vector<Actor*> arrows = GetActorsByGroup("PROJECTILE");
    std::vector<Actor*> enemyList1 = GetActorsByGroup("ENEMY");

    // Enemy Collisions
    for (auto arrow : arrows)
    {
        // Kill Arrow on Border Collision
        if (CalculateCollisionBorder(arrow))
        {
            Kill(arrow);
            std::cout << "BORDER HIT" << std::endl;
        }
    }
    std::vector<Physical*> melee = GetPhysicsByGroup("MELEE");
    for (auto mel : melee)
    {
        Melee* temp = static_cast<Melee*>(mel);
        if (temp->cooldown >= temp->maxCooldown)
            Kill(mel);
        for (auto e : enemyList1)
        {
            if (CalculateCollisionsBetween(e, mel))
            {
                e->Hurt(temp->GetDamage());
            }
        }
    }
    

}
