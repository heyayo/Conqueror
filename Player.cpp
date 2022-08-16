#include "Player.hpp"

Player::Player()
{
    Image img = GenImageColor(128,128,RED);
    Init(img);
    UnloadImage(img);
    Start();
}

void Player::Start()
{
    x = 500;
    y = 500;
    angle = 0;
    SetCollisionSize(128);
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
    angle += IsKeyDown(KEY_E) - IsKeyDown(KEY_Q);
}

V2 Player::GetVelocity()
{
    return velocity;
}
