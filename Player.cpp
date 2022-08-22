#include "Player.hpp"
#include "Game.hpp"

Player::Player()
{
    Init("sprites/hero.png", V2(128,128));
    name = "PLAYER";
    groupName = "PLAYERS";
    groupID = 0;
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
        Arrow* temp = new Arrow();
        temp->SetParent(this);
        temp->SetRotation(angle);
        GetCurrentScene()->AddPhysical(temp);
        std::cout << temp->GetGroupName() << std::endl;
    }
}

V2 Player::GetVelocity()
{
    return velocity;
}

Player::~Player()
{
}
