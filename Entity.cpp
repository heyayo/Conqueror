#include "Entity.hpp"

void Entity::Draw()
{
    DrawTexturePro(tex,rect,Rectangle{x,y,texW,texH},{texW/2,texH/2},angle,WHITE);
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

float Entity::GetX()
{
    return x;
}

float Entity::GetY()
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

void Entity::Init(const char *imgSrc)
{
    tex = LoadTexture(imgSrc);
    texW = tex.width;
    texH = tex.height;
    rect = {(float)texW,(float)texH};
}

void Entity::Init(Image &imgSrc)
{
    tex = LoadTextureFromImage(imgSrc);
    texW = tex.width;
    texH = tex.height;
    rect = {(float)texW,(float)texH};
}

void Entity::Init(const char *imgSrc, V2 resize)
{
    Image temp = LoadImage(imgSrc);
    ImageResize(&temp, resize.x, resize.y);
    tex = LoadTextureFromImage(temp);
    UnloadImage(temp);
    texW = tex.width;
    texH = tex.height;
    rect = {(float)texW,(float)texH};
}

Entity *Entity::GetParent()
{
    return parent;
}

void Entity::SetParent(Entity *newParent)
{
    parent = newParent;
}
