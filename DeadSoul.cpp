#include "DeadSoul.hpp"
#include "Game.hpp"
#include "TextBox.hpp"

TextBox* messageBox;
Physical* playerptr;

DeadSoul::DeadSoul(std::string* list, unsigned c) : msgList(list), count(c)
{
    Init("sprites/dead guy.png", V2(256,256));
    AutoCollider();
}

void DeadSoul::Start()
{
    V2 side = GetPosition();
    messageBox = new TextBox(msgList, count);
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
