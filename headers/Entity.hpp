#ifndef PROTOTYPE_ENTITY_HPP
#define PROTOTYPE_ENTITY_HPP

#include "raylib.h"

class Entity
{
protected:
    Texture2D tex;
    int x,y;
public:
    virtual ~Entity();

    void Draw();
    void Move(int,int);
    void Move(Vector2);
    virtual void Update() = 0;
    virtual void Start() = 0;
};


#endif
