#include "Skeleton.hpp"

Skeleton::Skeleton()
{
	health = 30;
	attack = 6;
	movspd = 5;
	atkspd = 20;
	Init("sprites/skele move.png", V2(128, 128));
	name = "ENEMY";
	groupName = "ENEMIES";
	
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
