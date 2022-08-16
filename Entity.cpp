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

void Entity::Move(Vector2 nv)
{
    x+=nv.x;
    y+=nv.y;
}

Entity::~Entity()
{
    UnloadTexture(tex);
}
