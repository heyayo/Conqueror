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
    std::string m[6];
    m[0] = "RIDE WIFE";
    m[1] = "LIFE GOOD";
    m[2] = "WIFE FIGHT BACK";
    m[3] = "KILL WIFE";
    m[4] = "WIFE GONE";
    m[5] = "REGRET";
    messageBox = new TextBox(m, 6);
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
    messageBox->SetPosition(GetScreenCenter());
    messageBox->SetPadding(V2(1000,800));
    messageBox->SetAlignment(TextBox::CENTER);
    messageBox->SetSpacing(2);
    messageBox->SetFontSize(150);
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
