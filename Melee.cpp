#include "Melee.hpp"

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
}
