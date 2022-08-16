#include "Character.hpp"

Character::Character(const char *imgSrc) : Physical(imgSrc)
{
    tex = LoadTexture(imgSrc);
    x = 0;
    y = 0;
}

Character::Character(Image imgSrc) : Physical(imgSrc)
{
    tex = LoadTextureFromImage(imgSrc);
    x = 0;
    y = 0;
}

Character::Character(const char *imgSrc, int resizeX, int resizeY) : Physical(imgSrc,resizeX,resizeY)
{
    Image img = LoadImage(imgSrc);
    ImageResize(&img, resizeX, resizeY);
    tex = LoadTextureFromImage(img);
    UnloadImage(img);
    x = 0;
    y = 0;
}
