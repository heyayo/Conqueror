#include "Arrow.hpp"
#include <math.h>
#include "Maths.hpp"

void Arrow::Update()
{
    Move(sin(Maths::DTR(-angle)) * speed,cos(Maths::DTR(-angle)) * speed);
}

void Arrow::Start()
{
    SetPosition(parent->GetPosition());
    SetCollisionSize(32);
    groupID = 2;
    groupName = "PROJECTILE";

}

Arrow::Arrow()
{
    health = 0;
    damage = 20;
}
