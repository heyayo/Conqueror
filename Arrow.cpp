#include "Arrow.hpp"
#include <math.h>
#include "Maths.hpp"

void Arrow::Update()
{
    Move(sin(Maths::DTR(-angle)) * speed,cos(Maths::DTR(-angle)) * speed);
}

void Arrow::Start()
{
    Init("sprites/arrow.png", V2(32,96));
    SetPosition(parent->GetPosition());
    SetCollisionSize(32);
    groupID = 2;
    groupName = "PROJECTILE";
}

Arrow::Arrow(float dmg)
{
    health = 0;
    damage = dmg;
}
