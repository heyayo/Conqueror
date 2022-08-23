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
    void Hurt(const float& dmg);

    float GetHealth() const;
    float GetDamage() const;
    V2 GetVelocity() const;
};


#endif
