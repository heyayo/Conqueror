#ifndef PROTOTYPE_PLAYER_HPP
#define PROTOTYPE_PLAYER_HPP

#include "Character.hpp"

class Player : public Character
{
public:
    Player(const char* imgSrc);
    Player(Image imgSrc);
    Player(const char* imgSrc, int resizeX, int resizeY);

    void Update() override;
    void Start() override;
    void InputHandler();
};


#endif
