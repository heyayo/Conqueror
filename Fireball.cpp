#include "Fireball.hpp"
#include "Maths.hpp"
#include <cmath>

Fireball::Fireball(float dmg)
{
    health = 0;
    damage = dmg;
}

void Fireball::Start()
{
    Init("sprites/fireball.png", V2(32,96));
    SetPosition(parent->GetPosition());
    SetCollisionSize(32);
    groupID = 2;
    groupName = "PROJECTILE";
}

void Fireball::Update()
{
    Move(sin(Maths::DTR(-angle)) * speed,cos(Maths::DTR(-angle)) * speed);
}
