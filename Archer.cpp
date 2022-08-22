#include "headers\Archer.h"
#include "Character.h"
#include "Arrow.hpp"
#include "Game.hpp"

Archer::Archer()
{
	Init("sprites/Archer move", V2(128, 128));
	health = 20;
	baseAtk = 6;
	atkSpd = 15;
	speed = 10;
}

Archer::~Archer()
{

}

void Archer::Update()
{
	InputHandler();
	Move(velocity);
	if (IsKeyPressed(KEY_SPACE))
	{
		std::cout << "SHOOTING" << std::endl;
		Arrow* temp = new Arrow();
		temp->Init("sprites/archer_attack.png", V2(32, 96));
		temp->SetParent(this);
		temp->SetRotation(angle);
		GetCurrentScene()->AddPhysical(temp);

	}

}

void Archer::Start()
{

}


