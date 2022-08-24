#ifndef PROTOTYPE_PLAYER_HPP
#define PROTOTYPE_PLAYER_HPP

#include "Actor.hpp"
#include "Arrow.hpp"

class Player : public Actor
{
public:
    enum CLASS
    {
        WARRIOR,
        ARCHER,
        MAGIC
    };

private:
    float speed = 5;
    CLASS classType;
    unsigned JournalCount = 0;

public:
    Player();
    Player(float hp, float dmg, unsigned JC, CLASS type);
    ~Player();

    Entity* MakeCopy();

    void Update() override;
    void Start() override;
    void InputHandler();
};

#endif
