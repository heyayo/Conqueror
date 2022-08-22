#include "Actor.hpp"

void Actor::Hurt(const float& dmg)
{
    health -= dmg;
}

float Actor::GetHealth() const
{
    return health;
}

float Actor::GetDamage() const
{
    return damage;
}

Actor::Actor()
{
    EType = ACTOR;
}
