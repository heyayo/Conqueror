#ifndef PROTOTYPE_PLAYER_HPP
#define PROTOTYPE_PLAYER_HPP

#include "Actor.hpp"
#include "Arrow.hpp"

class Player : public Actor
{
    V2 velocity;
    float speed = 5;

public:
    Player();
    Player(float spd);
    ~Player();

    V2 GetVelocity();

    Entity* MakeCopy();

    void Update() override;
    void Start() override;
    void InputHandler();
};

#endif
