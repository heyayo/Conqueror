#ifndef PROTOTYPE_PHYSICAL_HPP
#define PROTOTYPE_PHYSICAL_HPP

#include "Entity.hpp"

class Physical : public Entity
{
    int xCol, yCol;

public:
    Physical();

    int GetColX();
    int GetColY();
    V2 GetColSize();

    void AutoCollider();
    void SetCollisionSize(int size);
    void SetCollisionSize(V2 size);

    void Update();
    void Start();
};


#endif
