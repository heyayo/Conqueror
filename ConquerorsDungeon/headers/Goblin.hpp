#ifndef PROTOTYPE_GOBLIN_HPP
#define PROTOTYPE_GOBLIN_HPP

#include "Enemy.hpp"

class Goblin : public Enemy
{

public:
    Goblin();
    ~Goblin();

    void Update() override;
    void Start() override;
};

#endif
