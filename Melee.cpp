#include "Melee.hpp"
#include <cmath>
#include "Maths.hpp"

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
    psizealt.x = Maths::RTD(sin(parent->GetRotation())*psize.x);
    psizealt.y = Maths::RTD(cos(parent->GetRotation())*psize.y);
    Move(psizealt);
}
