#include "Slime.hpp"

Slime::Slime()
{
	Init("sprites/slime move.png", V2(128, 128));
	x = 1000;
	y = 1010;
    groupName = "ENEMY";
    groupID = 1;
    health = 100;
}

void Slime::Update()
{
}

void Slime::Start()
{
	angle = 0;
}
