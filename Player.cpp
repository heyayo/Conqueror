#include "Player.hpp"
#include "Game.hpp"
#include "Melee.hpp"

Player::Player()
{
    Init("sprites/warrior move.png", V2(128,128));
    name = "PLAYER";
    groupName = "PLAYERS";
    groupID = 0;
    health = 100;
    damage = 50;
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
    }
    /*if (IsKeyPressed(KEY_SPACE))
    {
        Melee* temp = new Melee();
        temp->SetParent(this);
        temp->Init(GREEN,GetSize());
        temp->SetRotation(angle);
        temp->maxCooldown = 10;
        GetCurrentScene()->AddPhysical(temp);
    }*/
}

V2 Player::GetVelocity()
{
    return velocity;
}

Player::~Player()
{
}

Entity *Player::MakeCopy()
{
    return new Player(this->speed);
}

Player::Player(float spd) : speed(spd)
{
}
