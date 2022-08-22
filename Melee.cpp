#include "headers\Melee.h"

Melee::Melee()
{
	groupID = 3;


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
