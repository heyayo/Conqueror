#ifndef PROTOTYPE_ENEMYFIREBALL_HPP
#define PROTOTYPE_ENEMYFIREBALL_HPP

#include "Actor.hpp"

class EnemyFireball : public Actor
{
    float speed = 15;
public:
    EnemyFireball(float dmg);

    void Start() override;
    void Update() override;
};


#endif
