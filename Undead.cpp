#include "Undead.hpp"

Undead::Undead()
{
	health = 30;
	attack = 8;
	movspd = 5;
	atkspd = 30;
	Init("sprites/undead move.png", V2(128, 128));
}

Undead::~Undead()
{
}

void Undead::Update()
{
}

void Undead::Start()
{
	x = 800;
	y = 800;
	angle = 0;
}
