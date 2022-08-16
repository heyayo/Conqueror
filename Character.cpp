#include "Character.hpp"


Character::Character(const char *imgSrc)
{
    health = 0;
    damage = 0;
    stamina = 0;
    staminaMax = 0;
    tex = LoadTexture(imgSrc);
    x = 0;
    y = 0;
    xCol = 0;
    yCol = 0;
}

Character::Character(Image imgSrc)
{
    health = 0;
    damage = 0;
    stamina = 0;
    staminaMax = 0;
    tex = LoadTextureFromImage(imgSrc);
    x = 0;
    y = 0;
    xCol = 0;
    yCol = 0;
}

Character::Character(const char *imgSrc, int resizeX, int resizeY)
{
    health = 0;
    damage = 0;
    stamina = 0;
    staminaMax = 0;
    Image img = LoadImage(imgSrc);
    ImageResize(&img, resizeX, resizeY);
    tex = LoadTextureFromImage(img);
    UnloadImage(img);
    x = 0;
    y = 0;
    xCol = 0;
    yCol = 0;
}

void Character::SetCollisionSize(int xC, int yC)
{
    xCol = xC;
    yCol = yC;
}

void Character::SetCollisionSize(Vector2 C)
{
    xCol = C.x;
    yCol = C.y;
}
