#include "Door.hpp"
#include "Player.hpp"

Door::Door()
{
    Init("sprites/Door.png",V2(64,64));
}

Player* PlayerPtr;

void Door::Start()
{
    PlayerPtr = static_cast<Player*>(GetCurrentScene()->GetPhysicsByName("PLAYER"));
}

void Door::Update()
{
    if (GetCurrentScene()->CalculateCollisionsBetween(this, PlayerPtr))
    {
        SaveState update = LoadSave();
        update.health = PlayerPtr->GetHealth();
        update.damage = PlayerPtr->GetDamage();
        update.speed = PlayerPtr->GetSpeed();
        update.armour = PlayerPtr->GetArmour();
        update.JournalCount = PlayerPtr->GetJournalCount();
        update.currentLevel = update.currentLevel;
        CreateSave(update);
        LoadSceneByEnum(toLoad);
    }
}

void Door::Redirect(SCENES leadTo){toLoad = leadTo;}
