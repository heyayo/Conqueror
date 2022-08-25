#ifndef PROTOTYPE_FIREBALL_HPP
#define PROTOTYPE_FIREBALL_HPP

#include "Actor.hpp"

class Fireball : public Actor
{
    float speed = 10;
public:
    Fireball(float dmg);

    void Start() override;
    void Update() override;
};


#endif
