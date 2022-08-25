
#pragma once
#include "Physical.hpp"
#include "Character.hpp"
#include "Player.hpp"

class Chest : public Physical
{


public:
    Chest();
    ~Chest();

    void Update() override;
    void Start() override;

};
