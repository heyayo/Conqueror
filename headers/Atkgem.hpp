
#pragma once
#include "Physical.hpp"
#include "Character.hpp"
#include "Player.hpp"

class Atkgem : public Physical
{


public:
    Atkgem();
    ~Atkgem();

    void Update() override;
    void Start() override;

};
