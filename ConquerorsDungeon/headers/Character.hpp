#ifndef PROTOTYPE_CHARACTER_HPP
#define PROTOTYPE_CHARACTER_HPP

#include "Actor.hpp"

class Character : public Actor
{
public:
    enum CLASS
    {
        WARRIOR,
        ARCHER,
        MAGIC
    };
protected:
    float maxStamina;
    int stamina;
    int atkSpd;
    float speed;
    unsigned JournalCount = 0;
    CLASS classType;

public:
    Character();
    Character(float hp, float aspd, float spd, float dmg, unsigned JC, CLASS type);

    Character* MakeCopy() override;
    CLASS GetClassType();

    void Update() override;
    void Start() override;
    void InputHandler();
};


#endif
