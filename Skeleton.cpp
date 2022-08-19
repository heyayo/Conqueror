#include "Skeleton.hpp"

Skeleton::Skeleton()
{
	Init("sprites/skele move.png", V2(128, 128));
}

Skeleton::~Skeleton()
{

}

void Skeleton::Update()
{
}

void Skeleton::Start()
{
	x = 600;
	y = 600;
	angle = 0;
}
