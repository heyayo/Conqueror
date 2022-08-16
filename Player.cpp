#include "Player.hpp"

Player::Player(const char *imgSrc) : Physical(imgSrc){ Start(); }
Player::Player(Image &imgSrc) : Physical(imgSrc){ Start(); }
Player::Player(const char *imgSrc, int resizeX, int resizeY) : Physical(imgSrc, resizeX, resizeY){ Start(); }

void Player::Start()
{
    x = 500;
    y = 500;
    SetCollisionSize(V2(128,128));
    velocity = V2();
}

// Put Player Code Here
void Player::Update()
{
    InputHandler();
    Move(velocity);
}

// Handle Input Here
void Player::InputHandler()
{
    velocity.x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    velocity.y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
}

V2 Player::GetVelocity()
{
    return velocity;
}
