#ifndef PROTOTYPE_ARROW_HPP
#define PROTOTYPE_ARROW_HPP

#include "Physical.hpp"

class Arrow : public Physical
{
    float speed = 20;

public:

    void Update() override;
    void Start() override;
};


#endif
