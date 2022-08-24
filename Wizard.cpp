#include "Wizard.hpp"
#include "Fireball.hpp"
#include "Game.hpp"

void Wizard::Start()
{
}

void Wizard::Update()
{
    InputHandler();
    Move(velocity);
    if (IsKeyPressed(KEY_SPACE))
    {
        Fireball* temp = new Fireball(damage);
        temp->Init("sprites/arrow.png", V2(32, 96));
        temp->SetParent(this);
        temp->SetRotation(angle);
        GetCurrentScene()->AddPhysical(temp);
    }
}

Wizard::Wizard()
{
    Init("sprites/wizard move.png", V2(128, 128));
    health = 50;
    damage = 10;
    atkSpd = 5;
    speed = 10;
    maxStamina = 250;
    stamina = maxStamina;
    classType = MAGIC;
}
