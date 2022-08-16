#include "Physical.hpp"


Physical::Physical()
{
    xCol = 0;
    yCol = 0;
}

V2 Physical::GetColSize()
{
    return V2(xCol,yCol);
}

void Physical::SetCollisionSize(int size)
{
    xCol = size;
    yCol = size;
}

void Physical::SetCollisionSize(V2 size)
{
    xCol = size.x;
    yCol = size.y;
}

int Physical::GetColX()
{
    return xCol;
}

int Physical::GetColY()
{
    return yCol;
}

void Physical::AutoCollider()
{
    xCol = texW/2;
    yCol = texH/2;
}
