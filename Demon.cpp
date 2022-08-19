#include "headers\Demon.h"

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
	x = 1000;
	y = 1010;
	angle = 0;
}
