#include "TextBox.hpp"
#include "Game.hpp"

TextBox::TextBox(const char *nText, Color nColor, Color nBoxColor, unsigned int nFontSize, V2 newPadding)
: text(nText), textColor(nColor), boxColor(nBoxColor), fontSize(nFontSize)
{
    padding = V2(newPadding.x,-newPadding.y);
}

void TextBox::SetText(const char* newText){text = newText;}
void TextBox::SetFont(Font newFont){font = newFont;}
void TextBox::SetTextColor(Color color){textColor = color;}
void TextBox::SetFontSize(unsigned int newFontSize){fontSize = newFontSize;}

void TextBox::Start()
{
    Init(boxColor, GetBoxSize());
    switch (alignment)
    {
        case TOPLEFT:
            textOffset = {tex.width/2.f,tex.height/2.f};
            break;
        case CENTER:
        {
            V2 temp = GetTextSize();
            textOffset = {(temp.x)/2.f,(temp.y)/2.f};
        }
            break;
        case CUSTOM:
            break;
    }
}

void TextBox::Update()
{
    V2 temp = GetTextSize();
    DrawTextPro(font, text, ConvertTorlVector2(GetPosition()), textOffset, angle, fontSize, 0, textColor);
}

TextBox::~TextBox()
{
    UnloadFont(font);
}

void TextBox::SetAlignment(TextBox::Alignment align)
{
    alignment = align;
}

void TextBox::SetTextPosition(Vector2 vecPos)
{
    textOffset = vecPos;
}

V2 TextBox::GetBoxSize()
{
    return ConvertToV2(MeasureTextEx(font,text,fontSize,0)) + padding;
}

V2 TextBox::GetTextSize()
{
    return ConvertToV2(MeasureTextEx(font,text,fontSize,0));
}

