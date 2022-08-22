#ifndef PROTOTYPE_GOBLIN_HPP
#define PROTOTYPE_GOBLIN_HPP

#include "Physical.hpp"

class Goblin : public Physical
{
    V2 velocity;

public:
    Goblin();
    ~Goblin();

    void Update() override;
    void Start() override;
};


#endif
