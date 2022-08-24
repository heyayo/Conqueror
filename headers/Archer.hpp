#ifndef PROTOTYPE_ARCHER_HPP
#define PROTOTYPE_ARCHER_HPP

#include "Character.hpp"

class Archer : public Character
{

public:
    Archer();

    void Update() override;
    void Start() override;

};

#endif