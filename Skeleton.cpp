#include "Skeleton.hpp"

Skeleton::Skeleton()
{
	health = 20;
	damage = 6;
	movspd = 3;
	atkspd = 20;
	Init("sprites/skele move.png", V2(128, 128));
	name = "ENEMY";
	groupName = "ENEMY";
	groupID = 2;
}

Skeleton::~Skeleton()
{

}


void Skeleton::Update()
{
}

void Skeleton::Start()
{
	angle = 0;
}
