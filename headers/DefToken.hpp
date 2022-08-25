
#pragma once
#include "Physical.hpp"
#include "Character.hpp"
#include "Player.hpp"

class DefToken : public Physical
{


public:
    DefToken();
    ~DefToken();

    void Update() override;
    void Start() override;

};
