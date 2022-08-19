#include "Slime.hpp"

Slime::Slime()
{
	health = 10;
	attack = 1;
	movspd = 5;
	atkspd = 10;
	Init("sprites/slime move.png", V2(128, 128));
}

Slime::~Slime()
{
}

void Slime::Update()
{
}

void Slime::Start()
{
	x = 1000;
	y = 1010;
	angle = 0;
}
