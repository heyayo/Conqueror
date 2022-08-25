#ifndef PROTOTYPE_PLAYER_HPP
#define PROTOTYPE_PLAYER_HPP

#include "Actor.hpp"
#include "Arrow.hpp"

class Player : public Actor
{
private:
    unsigned JournalCount = 0;
    float speed = 1;
    float armour;
public:
    Player();
    Player(float hp, float dmg, unsigned JC);
    ~Player();
    void Hurt(const float& dmg);
    void TickJournalCount();

    unsigned GetJournalCount();
    float GetSpeed();
    float GetArmour();

    void Update() override;
    void Start() override;
    void InputHandler();
};

#endif
