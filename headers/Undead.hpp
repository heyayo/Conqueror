#ifndef PROTOTYPE_UNDEAD_HPP
#define PROTOTYPE_UNDEAD_HPP

#include "Physical.hpp"

class Undead : public Physical
{
	V2 velocity;

public:
    Undead();
    ~Undead();

    void Update() override;
    void Start() override;
};

#endif