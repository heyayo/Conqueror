#include "Melee.hpp"
#include <cmath>
#include "Maths.hpp"

Melee::Melee(float dmg)
{
	groupID = 3;
    groupName = "MELEE";
    health = 0;
    damage = dmg;
}

Melee::~Melee()
{
}

void Melee::Start()
{
    cooldown = 0;
    AutoCollider();
}

void Melee::Update()
{
    cooldown++;
	SetPosition(parent->GetPosition());
    V2 psize = parent->GetSize();
    V2 psizealt;
    psizealt.x = -sin(Maths::DTR(parent->GetRotation()))*psize.x;
    psizealt.y = cos((Maths::DTR(parent->GetRotation())))*psize.y;
    Move(psizealt);
}
