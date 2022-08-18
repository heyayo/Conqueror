#include "UiElement.hpp"

UIElement::UIElement(){ groupID = 99; name = "UIELEMENT"; }

bool UIElement::CalculateMouseCollision()
{
    V2 aPos = GetPosition();
    Vector2 bPos = GetMousePosition();
    V2 aDist = GetSize();

    int trueXDist = abs(aPos.x - bPos.x);
    int trueYDist = abs(aPos.y - bPos.y);

    return
    (aDist.x/2 >= trueXDist && aDist.y/2 >= trueYDist);
}
