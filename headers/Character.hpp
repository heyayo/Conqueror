#ifndef PROTOTYPE_CHARACTER_HPP
#define PROTOTYPE_CHARACTER_HPP

#include "Entity.hpp"

class Character : public Entity
{
    int xCol;
    int yCol;
protected:
    float health;
    float damage;
    float stamina;
    float staminaMax;

public:
    Character(const char* imgSrc);
    Character(Image imgSrc);
    Character(const char* imgSrc, int resizeX, int resizeY);

    void SetCollisionSize(int xC, int yC);
    void SetCollisionSize(Vector2 C);
};


#endif
