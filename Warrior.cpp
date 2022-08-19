#include "headers\Warrior.h"
#include "Character.h"
#include "Melee.h"
#include "Game.hpp"

Warrior::Warrior()
{
	Init("sprites/warrior move.png", V2(128, 128));
	health = 50;
	baseAtk = 10;
	maxStamina = 100;
	stamina = 100;
	atkSpd = 5;
	speed = 10;


}

Warrior::~Warrior()
{
}

void Warrior::Update()
{
	InputHandler();
	Move(velocity);
	if (IsKeyPressed(KEY_SPACE))
	{
		std::cout << "SHOOTING" << std::endl;
		Melee* temp = new Melee();
		temp->Init("sprites/warrior attack.png", V2(32, 96));
		temp->SetParent(this);
		temp->SetRotation(angle);
		GetCurrentScene()->AddEntity(temp);
	}
}

void Warrior::Start()
{
	x = 500;
	y = 500;
	angle = 0;
	SetCollisionSize(64);
	velocity = V2();
}
