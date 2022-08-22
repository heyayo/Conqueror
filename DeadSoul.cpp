#include "DeadSoul.hpp"
#include "Game.hpp"
#include "TextBox.hpp"

TextBox* messageBox;
Physical* playerptr;

DeadSoul::DeadSoul(const char* msg) : message(msg)
{
    Init(GREEN,V2(64,64));
}

void DeadSoul::Start()
{
    V2 side = GetPosition();
    messageBox = new TextBox(message);
    switch (orient)
    {
        case LEFT:
            side.x -= tex.width + messageBox->GetBoxSize().x;
            break;
        case RIGHT:
            side.x += tex.width + messageBox->GetBoxSize().x;
            break;
        case UP:
            side.y -= tex.height + messageBox->GetBoxSize().y;
            break;
        case DOWN:
            side.y += tex.height + messageBox->GetBoxSize().y;
            break;
    }
    messageBox->SetPosition(side);
    messageBox->SetPadding(V2(50,50));
    messageBox->SetAlignment(TextBox::CENTER);
    GetCurrentScene()->AddUI(messageBox);
    playerptr = GetCurrentScene()->GetPhysicsByName("PLAYER");
}

void DeadSoul::Update()
{
    messageBox->SetVisibility(GetCurrentScene()->CalculateCollisionsBetween(this, playerptr));
}

bool DeadSoul::isSpeaking()
{
    return speaking;
}

DeadSoul::TEXTORIENTATION DeadSoul::GetOrientation()
{
    return orient;
}

void DeadSoul::SetOrientation(DeadSoul::TEXTORIENTATION ori)
{
    orient = ori;
}
