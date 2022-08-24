#ifndef PROTOTYPE_Healthpot_HPP
#define PROTOTYPE_Healthpot_HPP

#include "Enemy.hpp"

class Healthpot : public Enemy
{
    V2 velocity;

public:
    Healthpot();
    ~Healthpot();

    void Update() override;
    void Start() override;
};

#endif

