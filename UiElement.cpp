#include "UiElement.hpp"

UIElement::UIElement(int xSize, int ySize, Color color)
{
    Image image;
    image.width = xSize;
    image.height = ySize;
    ImageDrawRectangle(&image,0,0,xSize,ySize,WHITE);
    tex = LoadTextureFromImage(image);
    x = 0;
    y = 0;
    UnloadImage(image);
}

UIElement::UIElement(Vector2 size, Color color)
{
    Image image;
    image.width = size.x;
    image.height = size.y;
    ImageDrawRectangle(&image,0,0,size.x,size.y,WHITE);
    tex = LoadTextureFromImage(image);
    x = 0;
    y = 0;
    UnloadImage(image);
}
