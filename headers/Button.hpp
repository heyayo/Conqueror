#ifndef PROTOTYPE_BUTTON_HPP
#define PROTOTYPE_BUTTON_HPP

#include "TextBox.hpp"

class Button : public TextBox
{
    V2 boxSize;
    void (*OnHover)();
    //void (*OnClick)();

    void MouseDetection();

public:
    Button(V2 size, const char* text = "");

    void SetPadding();
    void SetOnHover(void (*onHo)());

    void Start() override;
    void Update() override;
};


#endif
