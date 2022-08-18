#ifndef PROTOTYPE_TEXTBOX_HPP
#define PROTOTYPE_TEXTBOX_HPP

#include "UiElement.hpp"

class TextBox : public UIElement
{
public:
    enum Alignment
    {
        TOPLEFT,
        CENTER,
        CUSTOM
    };

private:
    const char* text;
    Font font = LoadFont("fonts/regina.ttf");
    unsigned fontSize;
    Color textColor;
    Color boxColor;
    Alignment alignment = TOPLEFT;
    Vector2 textOffset;
    V2 padding;

public:
    TextBox(const char *nText, Color nColor, Color nBoxColor, unsigned int nFontSize, V2 newPadding);
    ~TextBox();

    void SetText(const char* newText);
    void SetFont(Font newFont);
    void SetFontSize(unsigned newFontSize);
    void SetTextColor(Color color);
    void SetAlignment(Alignment align);
    void SetTextPosition(Vector2 vecPos);

    V2 GetBoxSize();
    V2 GetTextSize();

    void Start();
    void Update();
};


#endif
