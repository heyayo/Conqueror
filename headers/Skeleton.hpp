#ifndef PROTOTYPE_SKELETON_HPP
#define PROTOTYPE_SKELETON_HPP

#include "Physical.hpp"

class Skeleton : public Physical
{
    V2 velocity;

public:
    Skeleton();
    ~Skeleton();

    void Update() override;
    void Start() override;
};

#endif