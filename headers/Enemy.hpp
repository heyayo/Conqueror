
#ifndef PROTOTYPE_ENEMY_HPP
#define PROTOTYPE_ENEMY_HPP
#include "Actor.hpp"

class Enemy : public Actor
{
protected:
    bool canAttack = true;
    const int cooldown = 60;
    int currentCooldown = 0;
    float atkrate;
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
    void SetCooldown(int cool);

    virtual void Act();

};

#endif
