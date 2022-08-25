#include "Actor.hpp"

class Melee : public Actor
{
public:
	Melee(float dmg);
	~Melee();
	void Start();
	void Update();

    unsigned cooldown;
    unsigned maxCooldown;
};