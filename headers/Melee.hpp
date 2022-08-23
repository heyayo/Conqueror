#include "Actor.hpp"

class Melee : public Actor
{
public:
	Melee();
	~Melee();
	void Start();
	void Update();

    unsigned cooldown;
    unsigned maxCooldown;
};