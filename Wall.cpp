#include "Wall.hpp"

Wall::Wall()
{
    Image temp = GenImageColor(128,128,RED);
    Init(temp);
    UnloadImage(temp);
    Start();
}

void Wall::Start()
{
    AutoCollider();
}

void Wall::Update()
{

}
