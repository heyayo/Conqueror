#ifndef PROTOTYPE_DEMON_HPP
#define PROTOTYPE_DEMON_HPP

#include "Enemy.hpp"

class Demon : public Enemy
{
    V2 velocity;

public:
    Demon();
    ~Demon();

    void Update() override;
    void Start() override;
};


#endif
