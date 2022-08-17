#ifndef PROTOTYPE_SLIME_HPP
#define PROTOTYPE_SLIME_HPP

#include "Physical.hpp"

class Slime : public Physical
{
    V2 velocity;
    float speed = 5;

public:
    Slime();
    ~Slime();

    V2 GetVelocity();

    void Update() override;
    void Start() override;
    void InputHandler();
};


#endif
