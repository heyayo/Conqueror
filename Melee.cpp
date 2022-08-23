#include "Melee.hpp"
#include <cmath>

Melee::Melee()
{
	groupID = 3;
    groupName = "MELEE";
}

Melee::~Melee()
{

}

void Melee::Start()
{

}

void Melee::Update()
{
	SetPosition(parent->GetPosition());
    V2 psize = parent->GetSize();
    V2 psizealt;
    psizealt.x = sin(parent->GetRotation())*psize.x;
    psizealt.y = cos(parent->GetRotation())*psize.y;
    Move(psizealt);
}
