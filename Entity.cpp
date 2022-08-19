#include "Entity.hpp"
#include "Config.hpp"
#include <cmath>
#include "Maths.hpp"

Entity::~Entity()
{
    UnloadTexture(tex);
}

void Entity::Draw()
{
    DrawTexturePro(tex,
                   Rectangle{0,0,(float)tex.width,(float)tex.height},
                   Rectangle{DeltarizeX(x), DeltarizeY(y),DeltarizeX(tex.width),DeltarizeY(tex.height)},
                   {DeltarizeX(tex.width/2),DeltarizeY(tex.height/2)},
                   angle,
                   WHITE);
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

Entity *Entity::GetParent()
{
    return parent;
}
unsigned Entity::GetID()
{
    return groupID;
}

std::string Entity::GetName()
{
    return name;
}

float Entity::GetRotation()
{
    return angle;
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

void Entity::SetParent(Entity *newParent)
{
    parent = newParent;

}

void Entity::SetRotation(float angl)
{
    angle = angl;
}

void Entity::Init(const char *imgSrc)
{
    tex = LoadTexture(imgSrc);
}

void Entity::Init(Image &imgSrc)
{
    tex = LoadTextureFromImage(imgSrc);
}

void Entity::Init(const char *imgSrc, V2 resize)
{
    Image temp = LoadImage(imgSrc);
    ImageResize(&temp, resize.x, resize.y);
    tex = LoadTextureFromImage( temp);
    UnloadImage(temp);
}

void Entity::Init(Color color, V2 size)
{
    Image temp = GenImageColor(size.x,size.y,color);
    tex = LoadTextureFromImage(temp);
    UnloadImage(temp);
}

V2 Entity::GetSize()
{
    return V2(tex.width,tex.height);
}

void Entity::SetName(std::string newName)
{
    name = newName;
}

void Entity::SetID(unsigned int newID)
{
    groupID = newID;
}

void Entity::LookAtMouse()
{
    V2 mousePos = Maths::ConvertToV2(GetMousePosition());

    angle = -Maths::RTD(std::atan2(mousePos.x-DeltarizeX(x), mousePos.y-DeltarizeY(y)));
}
