#include "Enemy.hpp"
#include "Game.hpp"
#include "Maths.hpp"

Enemy::Enemy()
{
	movspd = 10;
	atkspd = 10;
	damage = 10;
    health = 10;
}

Enemy::~Enemy()
{
}

int Enemy::getX()
{
	return 0;
}

int Enemy::getY()
{
	return 0;
}

void Enemy::move()
{
}

void Enemy::attackchar()
{
}

int Enemy::setX()
{
    return 0;
}

int Enemy::setY()
{
    return 0;
}

Actor* ptrtoplayer;
void Enemy::Act()
{
    // Get the Player Pointer
    ptrtoplayer = GetCurrentScene()->GetActorByName("PLAYER");

    // Move Enemy towards Player
    V2 move = GetPosition();
    V2 targetPos = ptrtoplayer->GetPosition();
    velocity.x = move.x > targetPos.x ? -movspd : movspd;
    velocity.y = move.y > targetPos.y ? -movspd : movspd;
    Move(velocity);
    LookAt(ptrtoplayer);
    if (GetCurrentScene()->CalculateCollisionsBetween(ptrtoplayer,this) && canAttack)
    {
        ptrtoplayer->Hurt(this->GetDamage());
        canAttack = false;
        currentCooldown = 0;
    }
    if (!canAttack)
    {
        if (currentCooldown < cooldown)
        {
            currentCooldown++;
        }
        else
            canAttack = true;
    }
}

void Enemy::SetCooldown(int cool)
{
    cooldown = cool;
}
