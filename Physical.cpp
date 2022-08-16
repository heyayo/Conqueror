#include "Physical.hpp"


Physical::Physical(const char *imgSrc)
{
    tex = LoadTexture(imgSrc);
    texW = tex.width;
    texH = tex.height;
}

Physical::Physical(Image &imgSrc)
{
    tex = LoadTextureFromImage(imgSrc);
    texW = tex.width;
    texH = tex.height;
    xCol = texW/2;
    yCol = texH/2;
}

Physical::Physical(const char *imgSrc, int resizeX, int resizeY)
{
    Image img = LoadImage(imgSrc);
    texW = resizeX;
    texH = resizeY;
    ImageResize(&img, texW, texH);
    tex = LoadTextureFromImage(img);
    UnloadImage(img);
    xCol = texW/2;
    yCol = texH/2;
}

V2 Physical::GetColSize()
{
    return V2(xCol,yCol);
}

void Physical::SetCollisionSize(int xC, int yC)
{
    xCol = xC;
    yCol = yC;
}

void Physical::SetCollisionSize(V2 size)
{
    xCol = size.x;
    yCol = size.y;
}

int Physical::GetColX()
{
    return xCol;
}

int Physical::GetColY()
{
    return yCol;
}
