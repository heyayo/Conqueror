#include "Dragon.hpp"

Dragon::Dragon()
{
	health = 20;
	damage = 4;
	movspd = 2;
	atkspd = 10;
	Init("sprites/dragon move.png", V2(128, 192));
	name = "ENEMY";
	groupName = "ENEMY";
	groupID = 3;
}

Dragon::~Dragon()
{
}

void Dragon::Update()
{
}

void Dragon::Start()
{
	angle = 0;
}
