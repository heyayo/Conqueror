#ifndef PROTOTYPE_MATHS_HPP
#define PROTOTYPE_MATHS_HPP

#include "raylib.h"
#include "V2.hpp"

namespace Maths
{
    float DTR(float Degree);
    float RTD(float Radian);

    void ShiftTowards(int& victim, int target, int step);
    void ShiftTowards(float& victim, float target, float step);
    void Range(float &victim, float max);

    int max(int a, int b);
    int min(int a, int b);
    float max(float a, float b);
    float min(float a, float b);

    double Root(double num);

    Vector2 ConvertTorlVector2(V2 toConvert);
    V2 ConvertToV2(Vector2 toConvert);
    float RelativeX(float xPixel);
    float RelativeY(float yPixel);
}

#endif
