#include "Actor.hpp"

void Actor::Heal(const float& dmg)
{
    health += dmg;
}
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

V2 Actor::GetVelocity() const
{
    return velocity;
}

Actor::Actor(float hp, float dmg) : health(hp), damage(dmg)
{
}

float* Actor::GetHealthPtr()
{
    return &health;
}
