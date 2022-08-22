#ifndef PROTOTYPE_ARROW_HPP
#define PROTOTYPE_ARROW_HPP

#include "Actor.hpp"

class Arrow : public Actor
{
    float speed = 20;

public:
    Arrow();

    void Update() override;
    void Start() override;
};


#endif
