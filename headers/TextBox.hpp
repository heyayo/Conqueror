#ifndef PROTOTYPE_TEXTBOX_HPP
#define PROTOTYPE_TEXTBOX_HPP

#include "UiElement.hpp"
#include <vector>

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
    std::vector<std::string> msgList;
    Font font = LoadFont("fonts/regina.ttf");
    float fontSize = 18;
    Color textColor = WHITE;
    Color boxColor = BLACK;
    Alignment alignment = TOPLEFT;
    Vector2 textOffset;
    V2 padding;
    float spacing = 1;
    float lineSpacing = 2;
    Vector2 BoxSize;
    Vector2 TextSize;

    void TextBoxFormat();
    void TextBoxDraw();
    void UpdateBoxSize();
    void UpdateTextSize();

public:
    TextBox(std::string* messages, unsigned msgcount);
    ~TextBox();

    void SetTexts(std::string* messages, unsigned msgcount);
    void SetFont(Font newFont);
    void SetFontSize(float newFontSize);
    void SetTextColor(Color color);
    void SetBoxColor(Color color);
    void SetAlignment(Alignment align);
    void SetTextPosition(Vector2 vecPos);
    void SetPadding(V2 newPadding);
    void SetSpacing(float newSpacing);
    void AutoLineSpacing();

    V2 GetBoxSize();
    V2 GetTextSize();

    void Start() override;
    void Update() override;
};


#endif
