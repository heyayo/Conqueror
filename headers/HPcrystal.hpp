#pragma once
#include "Physical.hpp"
#include "Character.h"
#include "Player.hpp"

class HPcrystal : public Physical
{

        
public:
    HPcrystal();
    ~HPcrystal();

    void Update() override;
    void Start() override;

};
