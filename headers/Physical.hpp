#ifndef PROTOTYPE_PHYSICAL_HPP
#define PROTOTYPE_PHYSICAL_HPP

#include "Entity.hpp"

class Physical : public Entity
{
    int xCol, yCol;

public:
    Physical(const char* imgSrc);
    Physical(Image &imgSrc);
    Physical(const char* imgSrc, int resizeX, int resizeY);

    int GetColX();
    int GetColY();
    V2 GetColSize();

    void SetCollisionSize(int xC, int yC);
    void SetCollisionSize(V2 size);
};


#endif
