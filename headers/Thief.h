#pragma once
#include "Physical.hpp"
#include "Character.h"
#include "Player.hpp"

class Thief : public Character
{


public:
    Thief();
    ~Thief();

    void Update() override;
    void Start() override;

};