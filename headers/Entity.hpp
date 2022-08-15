#ifndef PROTOTYPE_ENTITY_HPP
#define PROTOTYPE_ENTITY_HPP

#include "raylib.h"

class Entity
{
protected:
    Texture2D tex;
    int x,y;
public:
    Entity(const char*);
    Entity(Image);
    Entity(const char*, int,int);
    ~Entity();

    void Draw();
    void Move(int,int);
    void Move(Vector2);
};


#endif
