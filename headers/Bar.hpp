#ifndef PROTOTYPE_BAR_HPP
#define PROTOTYPE_BAR_HPP

#include "UiElement.hpp"

class Bar : public UIElement
{
public:
    enum ORIENTATION
    {
        VERTICAL,
        HORIZONTAL
    };
private:
    Color barColor;
    float maxSize;
    float progress;
    float thickness;
    float maxValue;
    float* value = nullptr;
    float delta;
    ORIENTATION orient = HORIZONTAL;

public:
    Bar(float* toVal, float maxVal, Color barC, float maxS, float thick);

    void SetOrientation(ORIENTATION ori);

    void Start() override;
    void Update() override;
};


#endif
