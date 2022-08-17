#ifndef PROTOTYPE_ENTITY_HPP
#define PROTOTYPE_ENTITY_HPP

#include "raylib.h"
#include "V2.hpp"

class Entity
{
protected:
    Texture2D tex;
    float x,y;
    float angle = 0;
    Entity* parent;
    std::string name;
    unsigned groupID;

public:
    virtual ~Entity();

    void Init(const char* imgSrc);
    void Init(Image &imgSrc);
    void Init(const char* imgSrc, V2 resize);

    void Draw();
    void Move(int,int);
    void Move(V2);

    unsigned GetID();
    float GetX();
    float GetY();
    float GetRotation();
    V2 GetPosition();
    Entity* GetParent();
    std::string GetName();

    void SetPosition(int xPos, int yPos);
    void SetPosition(V2 newPos);
    void SetRotation(float angl);
    void SetParent(Entity* newParent);

    virtual void Update() = 0;
    virtual void Start() = 0;
};


#endif
