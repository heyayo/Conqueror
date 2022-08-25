#include "Healthpot.hpp"

Healthpot::Healthpot()
{

	damage = -40;
	Init("sprites/healthpot.png", V2(128, 192));
	name = "BUFF";
	groupName = "BUFF";
	groupID = 9;
}

Healthpot::~Healthpot()
{
}

void Healthpot::Update()
{
}

void Healthpot::Start()
{
	angle = 0;
}
