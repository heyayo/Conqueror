
#ifndef PROTOTYPE_ENEMY_HPP
#define PROTOTYPE_ENEMY_HPP
#include "Physical.hpp"

class Enemy : public Physical
{
protected:
	int health;
	int attack;
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
