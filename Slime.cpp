#include "Slime.hpp"

Slime::Slime()
{
	health = 80;
	damage = 3;
	movspd = 1;
	atkspd = 60;
	Init("sprites/slime move.png", V2(128, 128));
	x = 1000;
	y = 1010;
    groupName = "ENEMY";
    groupID = 1;
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
