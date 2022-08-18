#ifndef PROTOTYPE_TEXTBOX_HPP
#define PROTOTYPE_TEXTBOX_HPP

#include "UiElement.hpp"

class TextBox : public UIElement
{
public:
    enum Alignment
    {
        UNALIGNED,
        CENTER,
        CUSTOM
    };

private:
    const char* text;
    Font font = LoadFont("fonts/regina.ttf");
    unsigned fontSize;
    Color textColor;
    Alignment alignment = UNALIGNED;
    Vector2 TextPosition;

public:
    TextBox(const char* nText, Color nColor, unsigned nFontSize);
    ~TextBox();

    void SetText(const char* newText);
    void SetFont(Font newFont);
    void SetFontSize(unsigned newFontSize);
    void SetTextColor(Color color);
    void SetAlignment(Alignment align);
    void SetTextPosition(Vector2 vecPos);

    Vector2 CenterPos();

    void Start();
    void Update();
};


#endif
