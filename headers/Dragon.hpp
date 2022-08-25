#ifndef PROTOTYPE_Dragon_HPP
#define PROTOTYPE_Dragon_HPP

#include "Enemy.hpp"

class Dragon : public Enemy
{
    V2 velocity;

public:
    Dragon();
    ~Dragon();
    int cooldown = 0;
    int cooldown1 = 90;

    void Update() override;
    void Start() override;
    void Act() override;
};

#endif
