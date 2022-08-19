#ifndef PROTOTYPE_PLAYER_HPP
#define PROTOTYPE_PLAYER_HPP

#include "Physical.hpp"

class Player : public Physical
{
    V2 velocity;
    float speed = 5;

public:
    Player();
    ~Player();

    V2 GetVelocity();

    void Update() override;
    void Start() override;
    void InputHandler();
};

#endif
