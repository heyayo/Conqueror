#include "TextBox.hpp"
#include "Game.hpp"
#include "Maths.hpp"

TextBox::TextBox(std::string* messages, unsigned msgcount)
{
    for (int i = 0; i < msgcount; i++)
        msgList.push_back(messages[i]);
}

void TextBox::SetTexts(std::string* messages, unsigned msgcount){ msgList.clear(); for (int i = 0; i < msgcount; i++) {msgList.push_back(messages[i]);}}
void TextBox::SetFont(Font newFont){font = newFont;}
void TextBox::SetTextColor(Color color){textColor = color;}
void TextBox::SetFontSize(float newFontSize){fontSize = newFontSize;}
void TextBox::SetAlignment(TextBox::Alignment align){alignment = align;}
void TextBox::SetTextPosition(Vector2 vecPos){textOffset = vecPos;}
void TextBox::SetPadding(V2 newPadding){padding = V2(newPadding.x,-newPadding.y);}
void TextBox::SetBoxColor(Color color){boxColor = color;}

void TextBox::UpdateBoxSize()
{
    UpdateTextSize();
    BoxSize = Maths::ConvertTorlVector2(Maths::ConvertToV2(TextSize) + padding);
}

void TextBox::UpdateTextSize()
{
    unsigned highestIndex = 0;
    V2 sizes[msgList.size()];
    for (int i = 0; i < msgList.size(); i++)
    {
        sizes[i] = Maths::ConvertToV2(MeasureTextEx(font,msgList[i].c_str(),fontSize,spacing));
        if (i > 0)
        {
            if (sizes[i] > sizes[i-1])
            {
                highestIndex = i;
            }
        }
    }
    TextSize = Maths::ConvertTorlVector2(sizes[highestIndex]);
}

void TextBox::Start()
{
    AutoLineSpacing();
    if (hasTexture)
    {
        Init(boxImage);
    }
    else
        Init(boxColor, GetBoxSize());
    SetTextureFilter(font.texture,TEXTURE_FILTER_BILINEAR);
    TextBoxFormat();
}

void TextBox::Update()
{
    if (visible)
        TextBoxDraw();
}

TextBox::~TextBox()
{
    UnloadFont(font);
}

V2 TextBox::GetBoxSize()
{
    return Maths::ConvertToV2(BoxSize);
}

V2 TextBox::GetTextSize()
{
    return Maths::ConvertToV2(TextSize);
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
    const float toTop = BoxSize.y/2 - TextSize.y/2;
    Vector2 Pos = Maths::ConvertTorlVector2(GetPosition());
    for (int i = 0; i < msgList.size(); i++)
    {
        DrawTextPro(font,
                    msgList[i].c_str(),
                    {DeltarizeX(Pos.x), DeltarizeY(Pos.y)},
                    {textOffset.x, textOffset.y + toTop - (lineSpacing * i)},
                    angle,
                    fontSize,
                    spacing,
                    textColor);
    }
}

void TextBox::SetSpacing(float newSpacing)
{
    spacing = newSpacing;
}

void TextBox::AutoLineSpacing()
{
    UpdateTextSize();
    lineSpacing = TextSize.y;
    UpdateBoxSize();
}

void TextBox::SetBoxTexture(const char *imgsrc)
{
    if (hasTexture)
        UnloadImage(boxImage);
    UpdateBoxSize();
    boxImage = LoadImage(imgsrc);
    ImageResize(&boxImage, BoxSize.x,BoxSize.y);
    hasTexture = true;
}

void TextBox::SetBoxTexture(Image &img)
{
    if (hasTexture)
        UnloadImage(boxImage);
    boxImage = img;
    hasTexture = true;
}

