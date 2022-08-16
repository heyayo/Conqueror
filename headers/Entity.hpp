#ifndef PROTOTYPE_ENTITY_HPP
#define PROTOTYPE_ENTITY_HPP

#include "raylib.h"
#include "V2.hpp"

class Entity
{
protected:
    Rectangle rect;
    Texture2D tex;
    float texW,texH;
    float x,y;
    float angle;
    Entity* parent;

public:
    virtual ~Entity();

    void Init(const char* imgSrc);
    void Init(Image &imgSrc);
    void Init(const char* imgSrc, V2 resize);

    void Draw();
    void Move(int,int);
    void Move(V2);

    float GetX();
    float GetY();
    V2 GetPosition();
    Entity* GetParent();

    void SetPosition(int xPos, int yPos);
    void SetPosition(V2 newPos);
    void SetParent(Entity* newParent);

    virtual void Update() = 0;
    virtual void Start() = 0;
};


#endif
