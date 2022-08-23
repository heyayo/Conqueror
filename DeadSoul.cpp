#include "DeadSoul.hpp"
#include "Game.hpp"
#include "TextBox.hpp"

TextBox* messageBox;
Physical* playerptr;

DeadSoul::DeadSoul(const char* msg) : message(msg)
{
    Init("sprites/dead guy.png", V2(80, 90));
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
    messageBox->SetPosition(GetScreenCenter());
    messageBox->SetPadding(V2(1000,800));
    messageBox->SetAlignment(TextBox::CENTER);
    messageBox->SetSpacing(2);
    messageBox->SetFontSize(150);
    messageBox->SetBoxTexture("sprites/scroll.png");
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
