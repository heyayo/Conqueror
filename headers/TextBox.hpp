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

protected:
    const char* text;
    Font font = LoadFont("fonts/regina.ttf");
    float fontSize = 18;
    Color textColor = WHITE;
    Color boxColor = BLACK;
    Alignment alignment = TOPLEFT;
    Vector2 textOffset;
    V2 padding;

    void TextBoxFormat();
    void TextBoxDraw();

public:
    TextBox(const char *nText);
    ~TextBox();

    void SetText(const char* newText);
    void SetFont(Font newFont);
    void SetFontSize(float newFontSize);
    void SetTextColor(Color color);
    void SetBoxColor(Color color);
    void SetAlignment(Alignment align);
    void SetTextPosition(Vector2 vecPos);
    void SetPadding(V2 newPadding);

    V2 GetBoxSize();
    V2 GetTextSize();

    void Start() override;
    void Update() override;
};


#endif
