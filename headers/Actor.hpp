#ifndef PROTOTYPE_ACTOR_HPP
#define PROTOTYPE_ACTOR_HPP

#include "Physical.hpp"

class Actor : public Physical
{
protected:
    float health;
    float damage;
    V2 velocity;

public:
    Actor();
    Actor(float hp, float dmg);
    void Hurt(const float& dmg);

    float GetHealth() const;
    float GetDamage() const;
    float* GetHealthPtr();
    V2 GetVelocity() const;

};


#endif
