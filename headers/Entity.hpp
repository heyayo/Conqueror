#ifndef PROTOTYPE_ENTITY_HPP
#define PROTOTYPE_ENTITY_HPP

#include "raylib.h"
#include "V2.hpp"

class Entity
{
public:
    enum TYPEOFENTITY
    {
        ENTITY,
        PHYSICAL,
        ACTOR,
        PLAYER,
        UIELEMENT
    };

protected:

    Texture2D tex;
    float x,y;
    float angle = 0;
    Entity* parent;
    std::string name;
    std::string groupName;
    unsigned groupID;
    TYPEOFENTITY EType;

public:
    Entity();
    virtual ~Entity();

    void Init(const char* imgSrc);
    void Init(Image &imgSrc);
    void Init(const char* imgSrc, V2 resize);
    void Init(Color color, V2 size);

    void Draw();
    void Move(int,int);
    void Move(V2);
    void LookAtMouse();
    void LookAt(Entity* toLook);

    unsigned GetID();
    float GetX();
    float GetY();
    float GetRotation();
    V2 GetPosition();
    V2 GetSize();
    Entity* GetParent();
    std::string GetGroupName();
    std::string GetName();
    TYPEOFENTITY GetTypeOfEntity();

    void SetPosition(int xPos, int yPos);
    void SetPosition(V2 newPos);
    void SetRotation(float angl);
    void SetParent(Entity* newParent);
    void SetName(std::string newName);
    void SetID(unsigned newID);

    virtual Entity* MakeCopy();

    virtual void Update() = 0;
    virtual void Start() = 0;
};


#endif
