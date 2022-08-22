#ifndef PROTOTYPE_UIELEMENT_HPP
#define PROTOTYPE_UIELEMENT_HPP

#include "Entity.hpp"

class UIElement : public Entity
{
protected:
    bool visible = true;
public:
    UIElement();
    bool CalculateMouseCollision();
    void SetVisibility(bool t);

    bool GetVisibility();
};


#endif
