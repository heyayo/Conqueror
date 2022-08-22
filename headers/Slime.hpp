#ifndef PROTOTYPE_SLIME_HPP
#define PROTOTYPE_SLIME_HPP

#include "Actor.hpp"

class Slime : public Actor
{

public:
    Slime();

    void Update() override;
    void Start() override;
};


#endif
