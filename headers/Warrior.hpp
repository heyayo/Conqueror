#ifndef PROTOTYPE_WARRIOR_HPP
#define PROTOTYPE_WARRIOR_HPP

#include "Character.hpp"

class Warrior : public Character
{
    unsigned AttackCooldown = 20;
public:
    Warrior();

    void Update() override;
    void Start() override;
    
};

#endif