#pragma once
#include "Physical.hpp"
#include "Character.h"
#include "Player.hpp"

class Warrior : public Character
{
 

public:
    Warrior();
    ~Warrior();

    void Update() override;
    void Start() override;
    
};