#include "Goblin.hpp"

Goblin::Goblin()
{
	health = 20;
	damage = 4;
	movspd = 2;
	atkspd = 10;
	Init("sprites/goblin move.png", V2(128, 128));
	name = "ENEMY";
	groupName = "ENEMY";
	groupID = 3;
}

Goblin::~Goblin()
{
}

void Goblin::Update()
{
}

void Goblin::Start()
{
	angle = 0;
}
