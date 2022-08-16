#include "Arrow.hpp"
#include <math.h>

void Arrow::Update()
{
    Move(sin(angle) * speed,cos(angle) * speed);
}

void Arrow::Start()
{
    SetPosition(parent->GetPosition());
    SetCollisionSize(32);
}
