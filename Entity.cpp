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

float Entity::GetX() { return x; }
float Entity::GetY() { return y; }
float Entity::GetRotation() { return angle; }
unsigned Entity::GetID() { return groupID; }
V2 Entity::GetPosition() { return V2(DeltarizeX(x),DeltarizeY(y)); }
V2 Entity::GetSize() { return V2(tex.width,tex.height); }
std::string Entity::GetGroupName() { return groupName; }
std::string Entity::GetName() { return name; }
Entity *Entity::GetParent() { return parent; }

void Entity::SetPosition(int xPos, int yPos)
{
    x = ODeltarizeX(xPos);
    y = ODeltarizeY(yPos);
}
void Entity::SetPosition(V2 newPos)
{
    x = ODeltarizeX(newPos.x);
    y = ODeltarizeY(newPos.y);
}
void Entity::SetParent(Entity *newParent) { parent = newParent; }
void Entity::SetRotation(float angl) { angle = angl; }
void Entity::SetName(std::string newName) { groupName = newName; }
void Entity::SetID(unsigned int newID) { groupID = newID; }

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

void Entity::LookAtMouse()
{
    V2 mousePos = Maths::ConvertToV2(GetMousePosition());

    angle = -Maths::RTD(std::atan2(mousePos.x-DeltarizeX(x), mousePos.y-DeltarizeY(y)));
}

void Entity::LookAt(Entity* toLook)
{
    V2 target = toLook->GetPosition();

    angle = -Maths::RTD(std::atan2(target.x-DeltarizeX(x), target.y-DeltarizeY(y)));
}

Entity::Entity()
{
    EType = ENTITY;
}

Entity::TYPEOFENTITY Entity::GetTypeOfEntity()
{
    return EType;
}

Entity* Entity::MakeCopy()
{
}
