#ifndef PROTOTYPE_TEXTBOX_HPP
#define PROTOTYPE_TEXTBOX_HPP

#include "UiElement.hpp"

class TextBox : public UIElement
{
    char* text;
public:
    TextBox(int xSize, int ySize, Color color);
    TextBox(Vector2 size, Color color);

    void SetText(char* newText);
};


#endif
