#include "PictureBox.hpp"
#include "Maths.hpp"

void PictureBox::Update()
{
    if (visible)
        DrawTextPro(font,caption.c_str(),Maths::ConvertTorlVector2(textPos),textOffset,0,fontSize,spacing,textColor);
}

void PictureBox::Start()
{
    Vector2 textSize = MeasureTextEx(font,caption.c_str(),fontSize,spacing);
    textPos = GetPosition();
    textOffset = {textSize.x/2,-tex.height/2.f};
    switch (orient)
    {
        case UP:
            textOffset.y += textSize.y;
            break;
        case DOWN:
            textOffset.y -= textSize.y;
            break;
    }
}

PictureBox::PictureBox(const char *imgsrc, V2 size)
{
    Image img = LoadImage(imgsrc);
    ImageResize(&img, size.x, size.y);
    tex = LoadTextureFromImage(img);
    UnloadImage(img);
}

PictureBox::PictureBox(const char *imgsrc, int xs, int ys)
{
    Image img = LoadImage(imgsrc);
    ImageResize(&img, xs,ys);
    tex = LoadTextureFromImage(img);
    UnloadImage(img);
}

void PictureBox::SetCaption(const char *newCap)
{
    caption = newCap;
}

void PictureBox::SetFontSize(float newFS)
{
    fontSize = newFS;
}

void PictureBox::SetSpacing(float newSpace)
{
    spacing = newSpace;
}

void PictureBox::SetOrientation(PictureBox::ORIENTATION ori)
{
    orient = ori;
}

void PictureBox::SetTextColor(Color newC)
{
    textColor = newC;
}
