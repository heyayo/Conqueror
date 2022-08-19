#include "TextBox.hpp"
#include "Game.hpp"
#include "Maths.hpp"

TextBox::TextBox(const char *nText)
: text(nText) {}

void TextBox::SetText(const char* newText){text = newText;}
void TextBox::SetFont(Font newFont){font = newFont;}
void TextBox::SetTextColor(Color color){textColor = color;}
void TextBox::SetFontSize(float newFontSize){fontSize = newFontSize;}
void TextBox::SetAlignment(TextBox::Alignment align){alignment = align;}
void TextBox::SetTextPosition(Vector2 vecPos){textOffset = vecPos;}
void TextBox::SetPadding(V2 newPadding){padding = V2(newPadding.x,-newPadding.y);}
void TextBox::SetBoxColor(Color color){boxColor = color;}

void TextBox::Start()
{
    Init(boxColor, GetBoxSize());
    SetTextureFilter(font.texture,TEXTURE_FILTER_BILINEAR);
    TextBoxFormat();
}

void TextBox::Update()
{
    TextBoxDraw();
}

TextBox::~TextBox()
{
    UnloadFont(font);
}

V2 TextBox::GetBoxSize()
{
    return Maths::ConvertToV2(MeasureTextEx(font,text,fontSize,0)) + padding;
}

V2 TextBox::GetTextSize()
{
    return Maths::ConvertToV2(MeasureTextEx(font,text,fontSize,0));
}

void TextBox::TextBoxFormat()
{
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

void TextBox::TextBoxDraw()
{
    V2 temp = GetTextSize();
    Vector2 Pos = Maths::ConvertTorlVector2(GetPosition());
    DrawTextPro(font, text, {DeltarizeX(Pos.x), DeltarizeY(Pos.y)}, textOffset, angle, fontSize, 0, textColor);
}

