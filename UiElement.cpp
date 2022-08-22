#include "Config.hpp"
#include "UiElement.hpp"

UIElement::UIElement(){ groupID = 99; groupName = "UIELEMENT"; name = "GENERICUI"; EType = UIELEMENT; }

bool UIElement::CalculateMouseCollision()
{
    V2 delta = GetScreenDelta();
    V2 aPos = GetPosition() * delta;
    Vector2 bPos = GetMousePosition();
    V2 aDist = GetSize();

    int trueXDist = abs(aPos.x - bPos.x);
    int trueYDist = abs(aPos.y - bPos.y);

    return
    (aDist.x/2 >= trueXDist && aDist.y/2 >= trueYDist);
}

void UIElement::SetVisibility(bool t)
{
    visible = t;
}

bool UIElement::GetVisibility()
{
    return visible;
}
