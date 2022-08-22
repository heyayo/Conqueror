#include "Physical.hpp"

Physical::Physical()
{
    xCol = 0;
    yCol = 0;
    groupID = 0;
    groupName = "ALL";
    EType = PHYSICAL;
}

void Physical::Update(){}
void Physical::Start(){}

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
    xCol = tex.width/2;
    yCol = tex.height/2;
}
