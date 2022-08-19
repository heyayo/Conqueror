#include "Player.hpp"
#include "Game.hpp"
#include "Arrow.hpp"

Player::Player()
{
    Init("sprites/hero.png", V2(128,128));
}

void Player::Start()
{
    x = 500;
    y = 500;
    angle = 0;
    SetCollisionSize(64);
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
    velocity.x = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * speed;
    velocity.y = (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * speed;
    LookAtMouse();

    if (IsKeyPressed(KEY_SPACE))
    {
        std::cout << "SHOOTING" << std::endl;
        Arrow* temp = new Arrow();
        temp->Init("sprites/arrow.png", V2(32,96));
        temp->SetParent(this);
        temp->SetRotation(angle);
        GetCurrentScene()->AddEntity(temp);
    }
}

V2 Player::GetVelocity()
{
    return velocity;
}

Player::~Player()
{
}
