
#ifndef PROTOTYPE_ENEMY_HPP
#define PROTOTYPE_ENEMY_HPP
#include "Actor.hpp"

class Enemy : public Actor
{
protected:
	int movspd;
	int atkspd;

public:
	Enemy();
	~Enemy();
	int getX();
	int getY();
	int setX();
	int setY();
	void move();
	void attackchar();

};

#endif
