
#include "Demon.h"

Demon::Demon()
{
	health = 200;
	damage = 5;
	movspd = 3;
	atkspd = 10;
	Init("sprites/demon move.png", V2(128, 128));
	name = "ENEMY";
	groupName = "ENEMY";
	groupID = 3;
}

Demon::~Demon()
{
}

void Demon::Update()
{
}

void Demon::Start()
{
	angle = 0;
}
