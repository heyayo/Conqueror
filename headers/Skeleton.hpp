#ifndef PROTOTYPE_SKELETON_HPP
#define PROTOTYPE_SKELETON_HPP

#include "Enemy.hpp"

class Skeleton : public Enemy
{
    V2 velocity;

public:
    Skeleton();
    ~Skeleton();

    void Update() override;
    void Start() override;
};

#endif