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
    angle += IsKeyDown(KEY_E) - IsKeyDown(KEY_Q);

    if (IsKeyPressed(KEY_SPACE))
    {
        std::cout << "SHOOTING" << std::endl;
        Arrow* temp = new Arrow();
        Image img = GenImageColor(16,16,GREEN);
        temp->Init(img);
        temp->SetParent(this);
        temp->SetRotation(angle);
        GetCurrentScene()->AddEntity(temp);
        UnloadImage(img);
    }
}

V2 Player::GetVelocity()
{
    return velocity;
}

Player::~Player()
{
}
