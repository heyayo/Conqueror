#ifndef PROTOTYPE_ENTITY_HPP
#define PROTOTYPE_ENTITY_HPP

#include "raylib.h"
#include "V2.hpp"

class Entity
{
protected:
    Texture2D tex;
    int texW,texH;
    int x,y;
public:
    virtual ~Entity();

    void Draw();
    void Move(int,int);
    void Move(V2);

    int GetX();
    int GetY();
    V2 GetPosition();

    void SetPosition(int xPos, int yPos);
    void SetPosition(V2 newPos);

    virtual void Update() = 0;
    virtual void Start() = 0;
};


#endif
