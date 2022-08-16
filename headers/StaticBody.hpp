#ifndef PROTOTYPE_STATICBODY_HPP
#define PROTOTYPE_STATICBODY_HPP

#include "Physical.hpp"

class StaticBody : public Physical
{

public:
    StaticBody(const char* imgSrc);
    StaticBody(Image &imgSrc);
    StaticBody(const char* imgSrc, int resizeX, int resizeY);

    void Update();
    void Start();
};


#endif
