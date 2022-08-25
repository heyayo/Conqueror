#include "Dragon.hpp"
#include "EnemyFireball.hpp"
#include "Game.hpp"
Dragon::Dragon()
{
	health = 100;
	damage = 60;
	movspd = 2;
	atkspd = 10;
	Init("sprites/dragon move.png", V2(256, 384));
	name = "ENEMY";
	groupName = "ENEMY";
	groupID = 3;
}

Dragon::~Dragon()
{
}

void Dragon::Update()
{
}

void Dragon::Start()
{
	angle = 0;
}

void Dragon::Act()
{
	if (cooldown >= cooldown1){
		EnemyFireball* temp = new EnemyFireball(damage);
		temp->SetParent(this);
		temp->SetRotation(angle);
		GetCurrentScene()->AddPhysical(temp);
		cooldown = 0;
	}
	else { cooldown += 1; }
}
