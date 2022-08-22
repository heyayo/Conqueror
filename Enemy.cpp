#include "Enemy.hpp"
#include "Game.hpp"
#include "Maths.hpp"

Enemy::Enemy()
{
	movspd = 10;
	atkspd = 10;
	
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

Physical* ptrtoplayer;
void Enemy::Act()
{
    ptrtoplayer = GetCurrentScene()->GetPhysicsByName("PLAYER");
    V2 move = GetPosition();
    V2 targetPos = ptrtoplayer->GetPosition();
    Maths::ShiftTowards(move.x, targetPos.x, movspd);
    Maths::ShiftTowards(move.y, targetPos.y, movspd);
    SetPosition(move);
}
