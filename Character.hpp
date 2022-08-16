#ifndef PROTOTYPE_CHARACTER_HPP
#define PROTOTYPE_CHARACTER_HPP

#include "Physical.hpp"

class Character : public Physical
{

public:
    Character(const char* imgSrc);
    Character(Image imgSrc);
    Character(const char* imgSrc, int resizeX, int resizeY);
};


#endif
