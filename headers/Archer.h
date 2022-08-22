#pragma once
#include "Physical.hpp"
#include "Character.h"
#include "Player.hpp"

class Archer : public Character
{


public:
    Archer();
    ~Archer();

    void Update() override;
    void Start() override;

};