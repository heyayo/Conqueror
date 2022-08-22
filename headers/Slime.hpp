#ifndef PROTOTYPE_SLIME_HPP
#define PROTOTYPE_SLIME_HPP

#include "Enemy.hpp"

class Slime : public Enemy
{
    V2 velocity;

public:
    Slime();
    ~Slime();

    void Update();
    void Start();
};


#endif
