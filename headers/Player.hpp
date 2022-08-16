#ifndef PROTOTYPE_PLAYER_HPP
#define PROTOTYPE_PLAYER_HPP

#include "Physical.hpp"

class Player : public Physical
{
    V2 velocity;
public:
    Player(const char* imgSrc);
    Player(Image &imgSrc);
    Player(const char* imgSrc, int resizeX, int resizeY);

    V2 GetVelocity();

    void Update() override;
    void Start() override;
    void InputHandler();
};


#endif
