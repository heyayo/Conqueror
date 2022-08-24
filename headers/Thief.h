#pragma once
#include "Physical.hpp"
#include "Character.hpp"
#include "Player.hpp"

class Thief : public Character
{


public:
    Thief();
    ~Thief();

    void Update() override;
    void Start() override;

};