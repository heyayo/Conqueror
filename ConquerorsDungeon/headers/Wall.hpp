#ifndef PROTOTYPE_WALL_HPP
#define PROTOTYPE_WALL_HPP

#include "StaticBody.hpp"

class Wall : public StaticBody
{

public:
    Wall();

    void Start();
    void Update();
};


#endif
