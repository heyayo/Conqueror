#pragma once
#include "Physical.hpp"
#include "Character.hpp"
#include "Player.hpp"

class HPcrystal : public Physical
{

        
public:
    HPcrystal();
    ~HPcrystal();

    void Update() override;
    void Start() override;

};
