#include "Character.hpp"

Character::Character()
{
	health = 0;
	baseAtk = 0;
	maxStamina = 0;
	stamina = 0;
	atkSpd = 0;
	speed = 0;
	armour = 0;
}

}

Character::Character(float hp, float aspd, float spd, float dmg, unsigned int JC, Character::CLASS type)
: Actor(hp,dmg), atkSpd(aspd), speed(spd), JournalCount(JC), classType(type)
{}

Character *Character::MakeCopy()
{
    return new Character(health,atkSpd,speed,damage,JournalCount,classType);
}

void Character::Update()
{
}

void Character::Start()
{
    Physical::Start();
}

void Character::InputHandler()
{
    velocity.x = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * speed;
    velocity.y = (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * speed;
    LookAtMouse();
}

Character::CLASS Character::GetClassType()
{
    return classType;
}
