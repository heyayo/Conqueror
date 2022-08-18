#ifndef PROTOTYPE_SLIME_HPP
#define PROTOTYPE_SLIME_HPP

#include "Physical.hpp"

class Slime : public Physical
{
    V2 velocity;

public:
    Slime();
    ~Slime();

    void Update() override;
    void Start() override;
};


#endif
