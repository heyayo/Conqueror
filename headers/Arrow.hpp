#ifndef PROTOTYPE_ARROW_HPP
#define PROTOTYPE_ARROW_HPP

#include "Physical.hpp"

class Arrow : public Physical
{
    float angle = 0;
    float speed = 5;

public:

    void Update();
    void Start();
};


#endif
