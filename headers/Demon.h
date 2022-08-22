#ifndef PROTOTYPE_DEMON_HPP
#define PROTOTYPE_DEMON_HPP

#include "Physical.hpp"

class Demon : public Physical
{
    V2 velocity;

public:
    Demon();
    ~Demon();

    void Update() override;
    void Start() override;
};


#endif
