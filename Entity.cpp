#include "Entity.hpp"

void Entity::Draw()
{
    DrawTexture(tex,x-x/2,y-y/2,WHITE);
}

void Entity::Move(int nx, int ny)
{
    x+=nx;
    y+=ny;
}

void Entity::Move(V2 nv)
{
    x+=nv.x;
    y+=nv.y;
}

Entity::~Entity()
{
    UnloadTexture(tex);
}

int Entity::GetX()
{
    return x;
}

int Entity::GetY()
{
    return y;
}

V2 Entity::GetPosition()
{
    return V2(x,y);
}

void Entity::SetPosition(int xPos, int yPos)
{
    x = xPos;
    y = yPos;
}

void Entity::SetPosition(V2 newPos)
{
    x = newPos.x;
    y = newPos.y;
}
