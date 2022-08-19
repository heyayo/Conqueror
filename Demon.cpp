#include "Demon.hpp"

Demon::Demon()
{
	Init("sprites/demon move.png", V2(128, 128));
}

Demon::~Demon()
{
}

void Demon::Update()
{
}

void Demon::Start()
{
	x = 00;
	y = 800;
	angle = 0;
}
