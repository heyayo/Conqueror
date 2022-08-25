#include "Bar.hpp"

Bar::Bar(float *toVal, float maxVal, Color barC, float maxS, float thick)
: value(toVal), maxValue(maxVal), barColor(barC), maxSize(maxS), thickness(thick)
{
    delta = maxSize / maxValue;
}

void Bar::Start()
{
    progress = delta * maxValue;
    switch (orient)
    {
        case HORIZONTAL:
            angle = 0;
            break;
        case VERTICAL:
            angle = 90;
            break;
    }
    Init(barColor,V2(progress,thickness));
}

void Bar::Update()
{
    if (progress != delta* *value)
    {
        Init(barColor,V2(progress,thickness));
        progress = delta * *value;
    }
}

void Bar::SetOrientation(Bar::ORIENTATION ori)
{
    orient = ori;
}
