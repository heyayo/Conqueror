#include "Undead.hpp"

Undead::Undead()
{
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
