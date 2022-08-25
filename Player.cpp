#include "Player.hpp"
#include "Game.hpp"
#include "Melee.hpp"
#include "Fireball.hpp"

Player::Player()
{
    name = "PLAYER";
    groupName = "PLAYERS";
    groupID = 0;
}

void Player::Start()
{
    switch(GetPlayersClass())
    {
        case ARCHER:
            Init("sprites/Archer move.png", V2(96,96));
            break;
        case WARRIOR:
            Init("sprites/warrior move.png", V2(128,128));
            break;
        case WIZARD:
            Init("sprites/wizard move.png", V2(96,96));
            break;
        case HUGHJACKMAN:
            Init("sprites/hughjackman.png", V2(128,128));
            break;
    }
    SaveState temp = LoadSave();
    health = temp.health;
    damage = temp.damage;
    speed = temp.speed;
    JournalCount = temp.JournalCount;
    x = 200;
    y = 500;
    angle = 0;
    velocity = V2();
    AutoCollider();
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
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Melee* temp = new Melee(damage);
                temp->SetParent(this);
                temp->Init(Color{255,0,0,30},GetSize());
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

void Player::TickJournalCount()
{
    ++JournalCount;
}

unsigned Player::GetJournalCount()
{
    return JournalCount;
}

float Player::GetSpeed()
{
    return speed;
}
