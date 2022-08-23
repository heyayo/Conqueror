#include "PictureBox.hpp"

void PictureBox::Update()
{

}

void PictureBox::Start()
{

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
