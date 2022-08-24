#include "Archer.hpp"
#include "Arrow.hpp"
#include "Game.hpp"

Archer::Archer()
{
	Init("sprites/Archer move.png", V2(128, 128));
	health = 20;
	damage = 6;
	atkSpd = 15;
	speed = 10;
    maxStamina = 100;
    stamina = maxStamina;
    groupName = "PLAYERS";
    groupID = 0;
    name = "ARCHER";
    classType = ARCHER;
}

void Archer::Update()
{
	InputHandler();
	Move(velocity);
	if (IsKeyPressed(KEY_SPACE))
	{
		Arrow* temp = new Arrow(damage);
		temp->Init("sprites/arrow.png", V2(32, 96));
		temp->SetParent(this);
		temp->SetRotation(angle);
		GetCurrentScene()->AddPhysical(temp);
	}
}

void Archer::Start()
{
    angle = 0;
    AutoCollider();
    velocity = V2();
}


