#include "Warrior.hpp"
#include "Melee.hpp"
#include "Game.hpp"

Warrior::Warrior()
{
	Init("sprites/warrior move.png", V2(128, 128));
	health = 50;
	damage = 10;
	atkSpd = 5;
	speed = 10;
    maxStamina = 100;
    stamina = maxStamina;
    classType = WARRIOR;
}

void Warrior::Update()
{
	InputHandler();
	Move(velocity);
	if (IsKeyPressed(KEY_SPACE))
	{
		Melee* temp = new Melee(damage);
		temp->Init("sprites/warrior attack.png", V2(32, 96));
		temp->SetParent(this);
		temp->SetRotation(angle);
        temp->maxCooldown = AttackCooldown;
        temp->cooldown = 0;
		GetCurrentScene()->AddPhysical(temp);
	}
}

void Warrior::Start()
{
	angle = 0;
    AutoCollider();
	velocity = V2();
}
