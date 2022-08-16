#include "TextBox.hpp"

TextBox::TextBox(Vector2 size, Color color) : UIElement(size, color)
{
    text = nullptr;
}

TextBox::TextBox(int xSize, int ySize, Color color) : UIElement(xSize, ySize, color)
{
    text = nullptr;
}

void TextBox::SetText(char *newText)
{
    text = newText;
}
