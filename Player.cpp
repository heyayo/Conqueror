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
    damage = 1;
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
    velocity.x = (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * 5;
    velocity.y = (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * 5;
    LookAtMouse();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Arrow* temp = new Arrow(damage);
        temp->SetParent(this);
        temp->SetRotation(angle);
        GetCurrentScene()->AddPhysical(temp);
    }
    /*if (IsKeyPressed(KEY_SPACE))
    {
        Melee* temp = new Melee(damage);
        temp->SetParent(this);
        temp->Init(GREEN,GetSize());
        temp->SetRotation(angle);
        temp->maxCooldown = 10;
        temp->cooldown = 0;
        GetCurrentScene()->AddPhysical(temp);
    }*/
}

Player::~Player()
{
}

Player::Player(float hp, float dmg, unsigned JC, CLASS type)
: Actor(hp,dmg), JournalCount(JC), classType(type)
{
}
