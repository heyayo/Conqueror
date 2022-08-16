#include "Player.hpp"

Player::Player(const char *imgSrc) : Character(imgSrc){ Start(); }
Player::Player(Image imgSrc) : Character(imgSrc){ Start(); }
Player::Player(const char *imgSrc, int resizeX, int resizeY) : Character(imgSrc, resizeX, resizeY){ Start(); }

void Player::Start()
{
    x = 500;
    y = 500;
}

// Put Player Code Here
void Player::Update()
{
    InputHandler();
}

// Handle Input Here
void Player::InputHandler()
{
    x += IsKeyDown(KEY_D);
    x -= IsKeyDown(KEY_A);
    y += IsKeyDown(KEY_S);
    y -= IsKeyDown(KEY_W);
}
