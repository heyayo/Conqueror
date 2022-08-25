
#pragma once
#include "Physical.hpp"
#include "Character.hpp"
#include "Player.hpp"

class AtkToken : public Physical
{


public:
    AtkToken();
    ~AtkToken();

    void Update() override;
    void Start() override;

};
