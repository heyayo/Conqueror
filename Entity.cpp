#include "Entity.hpp"

Entity::Entity(const char * textureLoc)
{
    tex = LoadTexture(textureLoc);
    x = 0;
    y = 0;
}

Entity::Entity(Image texture)
{
    tex = LoadTextureFromImage(texture);
    x = 0;
    y = 0;
}

Entity::Entity(const char* textureLoc, int width, int height)
{
    Image img = LoadImage(textureLoc);
    ImageResize(&img,width,height);
    tex = LoadTextureFromImage(img);
    x = 0;
    y = 0;
    UnloadImage(img);
}

void Entity::Draw()
{
    DrawTexture(tex,x,y,WHITE);
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
