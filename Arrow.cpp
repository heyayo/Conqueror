#include "Arrow.hpp"
#include <math.h>
#include "Maths.hpp"

void Arrow::Update()
{
    Move(sin(Maths::DTR(-angle)) * speed,cos(Maths::DTR(-angle)) * speed);
    std::cout << GetPosition() << std::endl;
}

void Arrow::Start()
{
    SetPosition(parent->GetPosition());
    std::cout << parent->GetPosition() << std::endl;
    SetCollisionSize(32);
    groupID = 2;
    name = "PROJECTILE";
}
