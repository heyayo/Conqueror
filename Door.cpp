#include "Door.hpp"

Door::Door()
{
    Init("sprites/Door.png",V2(64,64));
}

Physical* PlayerPtr;

void Door::Start()
{
    SetPosition(200,200);
    PlayerPtr = GetCurrentScene()->GetPhysicsByName("PLAYER");
}

void Door::Update()
{
    if (GetCurrentScene()->CalculateCollisionsBetween(this, PlayerPtr))
        LoadSceneByEnum(toLoad);
}

void Door::Redirect(SCENES leadTo){toLoad = leadTo;}
