#include "Button.hpp"
#include "Game.hpp"

Button::Button(V2 size, const char* text) : TextBox(text), boxSize(size)
{
}

void Button::Start()
{
    Init(boxColor, GetBoxSize()+boxSize);
    TextBoxFormat();
}

void Button::Update()
{
    TextBoxDraw();
}

void Button::SetOnHover(void (*onHo)())
{
    OnHover = onHo;
}

void Button::MouseDetection()
{
    if (CalculateMouseCollision())
    {
        OnHover();
    }
}
