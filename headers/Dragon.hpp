#ifndef PROTOTYPE_Dragon_HPP
#define PROTOTYPE_Dragon_HPP

#include "Enemy.hpp"

class Dragon : public Enemy
{
    V2 velocity;

public:
    Dragon();
    ~Dragon();

    void Update() override;
    void Start() override;
    void Act() override;
};

#endif
