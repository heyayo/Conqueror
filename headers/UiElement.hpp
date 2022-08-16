#ifndef PROTOTYPE_UIELEMENT_HPP
#define PROTOTYPE_UIELEMENT_HPP

#include "Entity.hpp"

class UIElement : public Entity
{
protected:
    Color color;

public:
    UIElement(int xSize, int ySize, Color color);
    UIElement(Vector2 size, Color color);
};


#endif
