#include "EnemyFireball.hpp" 
#include <math.h>
#include "Maths.hpp"

void EnemyFireball::Update()
{
    Move(sin(Maths::DTR(-angle)) * speed, cos(Maths::DTR(-angle)) * speed);
}

void EnemyFireball::Start()
{
    Init("sprites/fireball.png", V2(64, 64));
    SetPosition(parent->GetPosition());
    AutoCollider();
    groupID = 10;
    groupName = "ENEMYPROJECTILE";
}

EnemyFireball::EnemyFireball(float dmg)
{
    health = 0;
    damage = dmg;
}
