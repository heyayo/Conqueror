#include "StaticBody.hpp"

StaticBody::StaticBody(const char *imgSrc) : Physical(imgSrc)
{
    Start();
}

StaticBody::StaticBody(Image &imgSrc) : Physical(imgSrc)
{
    Start();
}

StaticBody::StaticBody(const char *imgSrc, int resizeX, int resizeY) : Physical(imgSrc, resizeX, resizeY)
{
    Start();
}

void StaticBody::Update()
{

}

void StaticBody::Start()
{
    SetPosition(V2(800,800));
    SetCollisionSize(V2(128,128));
}
