#ifndef PROTOTYPE_UNDEAD_HPP
#define PROTOTYPE_UNDEAD_HPP

#include "Physical.hpp"

class Demon : public Physical
{
    V2 velocity;

public:
    Demon();
    ~Demon();

    void Update() override;
    void Start() override;
};
#endif
