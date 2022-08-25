#include "Dragon.hpp"
#include "EnemyFireball.hpp"
#include "Game.hpp"
Dragon::Dragon()
{
	health = 100;
	damage = 40;
	movspd = 2;
	atkspd = 30;
	Init("sprites/dragon move.png", V2(256, 384));
    AutoCollider();
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
	if (currentCooldown >= atkrate){
		EnemyFireball* temp = new EnemyFireball(damage);
		temp->SetParent(this);
		temp->SetRotation(angle);
		GetCurrentScene()->AddPhysical(temp);
		currentCooldown = 0;
	}
	else { currentCooldown += 1; }
}
