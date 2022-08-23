#include "headers\Thief.h"
#include "Character.h"
#include "Melee.hpp"
#include "Game.hpp"

Thief::Thief()
{
	Init("sprites/assasin move.png", V2(128, 128));
	health = 10;
	baseAtk = 20;
	maxStamina = 100;
	stamina = 100;
	atkSpd = 20;
	speed = 10;
}

Thief::~Thief()
{
}

void Thief::Update()
{
	InputHandler();
	Move(velocity);
	if (IsKeyPressed(KEY_SPACE))
	{
		std::cout << "SHOOTING" << std::endl;
		Melee* temp = new Melee();
		temp->Init("sprites/assasin attacks.png", V2(32, 96));
		temp->SetParent(this);
		temp->SetRotation(angle);
		GetCurrentScene()->AddEntity(temp);
	}
}

void Thief::Start()
{
	x = 500;
	y = 500;
	angle = 0;
	SetCollisionSize(64);
	velocity = V2();
}
