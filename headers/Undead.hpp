#ifndef PROTOTYPE_UNDEAD_HPP
#define PROTOTYPE_UNDEAD_HPP

#include "Enemy.hpp"

class Undead : public Enemy
{
	V2 velocity;

public:
    Undead();
    ~Undead();

    void Update();
    void Start();
};

#endif