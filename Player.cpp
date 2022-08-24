#include "Player.hpp"
#include "Game.hpp"
#include "Melee.hpp"
#include "Fireball.hpp"

Player::Player()
{
    name = "PLAYER";
    groupName = "PLAYERS";
    groupID = 0;
    health = 100;
}

void Player::Start()
{
    switch(GetPlayersClass())
    {
        case ARCHER:
            damage = 1;
            std::cout << "ARCHER" << std::endl;
            Init("sprites/Archer move.png", V2(96,96));
            break;
        case WARRIOR:
            damage = 5;
            std::cout << "WARRIOR" << std::endl;
            Init("sprites/warrior move.png", V2(128,128));
            break;
        case WIZARD:
            damage = 3;
            std::cout << "WIZARD" << std::endl;
            Init("sprites/wizard move.png", V2(96,96));
            break;
        case HUGHJACKMAN:
            damage = 100;
            std::cout << "HUGHJACKMAN" << std::endl;
            Init("sprites/hughjackman.png", V2(256,256));
            break;
    }
    x = 200;
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

    switch(GetPlayersClass())
    {
        case ARCHER:
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Arrow* temp = new Arrow(damage);
                temp->SetParent(this);
                temp->SetRotation(angle);
                GetCurrentScene()->AddPhysical(temp);
            }
            break;
        case WARRIOR:
            if (IsKeyPressed(KEY_SPACE))
            {
                Melee* temp = new Melee(damage);
                temp->SetParent(this);
                temp->Init(GREEN,GetSize());
                temp->SetRotation(angle);
                temp->maxCooldown = 10;
                temp->cooldown = 0;
                GetCurrentScene()->AddPhysical(temp);
            }
            break;
        case WIZARD:
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Fireball* temp = new Fireball(damage);
                temp->SetParent(this);
                temp->SetRotation(angle);
                GetCurrentScene()->AddPhysical(temp);
            }
            break;
        case HUGHJACKMAN:
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Arrow* temp = new Arrow(damage);
                temp->SetParent(this);
                temp->SetRotation(angle);
                GetCurrentScene()->AddPhysical(temp);
                Fireball* fire = new Fireball(damage);
                fire->SetParent(this);
                fire->SetRotation(angle);
                GetCurrentScene()->AddPhysical(fire);
            }
            break;
    }
}

Player::~Player()
{
}

Player::Player(float hp, float dmg, unsigned JC)
: Actor(hp,dmg), JournalCount(JC)
{
}
