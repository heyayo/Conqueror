#include "headers\Character.h"

Character::Character()
{
	health = 0;
	baseAtk = 0;
	maxStamina = 0;
	stamina = 0;
	atkSpd = 0;
	speed = 0;
}

Character::~Character()
{
}

V2 Character::GetVelocity()
{
	return velocity;
}

void Character::Update()
{
}

void Character::Start()
{

}

void Character::InputHandler()
{
	velocity.x = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * speed;
	velocity.y = (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * speed;
	angle += IsKeyDown(KEY_E) - IsKeyDown(KEY_Q);
}
