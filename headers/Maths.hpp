#ifndef PROTOTYPE_MATHS_HPP
#define PROTOTYPE_MATHS_HPP

#include "raylib.h"

namespace Maths
{
    float DTR(float Degree);
    float RTD(float Radian);

    void ShiftTowards(int& victim, int target, int step);
    void ShiftTowards(float& victim, float target, float step);

    int max(int a, int b);
    int min(int a, int b);
    float max(float a, float b);
    float min(float a, float b);

    double Root(double num);
}

#endif
