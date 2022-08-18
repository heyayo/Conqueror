#include "TextBox.hpp"
#include "Game.hpp"

TextBox::TextBox(const char *nText, Color nColor, unsigned int nFontSize)
: text(nText), textColor(nColor), fontSize(nFontSize) {}

void TextBox::SetText(const char* newText){text = newText;}
void TextBox::SetFont(Font newFont){font = newFont;}
void TextBox::SetTextColor(Color color){textColor = color;}
void TextBox::SetFontSize(unsigned int newFontSize){fontSize = newFontSize;}

void TextBox::Start()
{
    switch (alignment)
    {
        case UNALIGNED:
            TextPosition = {x,y};
            break;
        case CENTER:
            TextPosition = CenterPos();
            break;
        case CUSTOM:
            break;
    }
}

void TextBox::Update()
{
    DrawTextPro(font,text, TextPosition,{tex.width/2.f,tex.height/2.f},0,fontSize,0,textColor);
}

TextBox::~TextBox()
{
    UnloadFont(font);
}

Vector2 TextBox::CenterPos()
{
    Vector2 textSize = MeasureTextEx(font,text,fontSize,0);
    return Vector2{x+(tex.width/2)-(textSize.x/2),y+(tex.height/2)-(textSize.y/2)};
}

void TextBox::SetAlignment(TextBox::Alignment align)
{
    alignment = align;
}

void TextBox::SetTextPosition(Vector2 vecPos)
{
    TextPosition = vecPos;
}

