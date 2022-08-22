#include "Slime.hpp"

Slime::Slime()
{
	health = 10;
	attack = 1;
	movspd = 5;
	atkspd = 10;
	Init("sprites/slime move.png", V2(128, 128));
	x = 1000;
	y = 1010;
    groupName = "ENEMY";
    groupID = 1;
    health = 100;
}

Slime::~Slime()
{
}

void Slime::Update()
{
}

void Slime::Start()
{
	angle = 0;
}
