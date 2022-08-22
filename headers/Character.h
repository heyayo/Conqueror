#pragma once
#ifndef PROTOTYPE_CHARACTER_HPP
#define PROTOTYPE_CHARACTER_HPP

#include "Physical.hpp"

class Character : public Physical
{
protected:
    float health;
    int baseAtk;
    float maxStamina;
    int stamina;
    int atkSpd;
    float speed;
    V2 velocity;

public:
    Character();
    ~Character();
    V2 GetVelocity();

    void Update() override;
    void Start() override;
    void InputHandler();
};


#endif
