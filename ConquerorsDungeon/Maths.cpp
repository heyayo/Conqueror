#include "Maths.hpp"

void Maths::ShiftTowards(int& victim, int target, int step)
{
    victim = Maths::max(Maths::min(victim + step, target), victim - step);
}
void Maths::ShiftTowards(float& victim, float target, float step)
{
    victim = Maths::max(Maths::min(victim + step, target), victim - step);
}

int Maths::max(int a, int b) { return (a>b)?a:b; }
int Maths::min(int a, int b) { return (a>b)?b:a; }
float Maths::max(float a, float b) { return (a>b)?a:b; }
float Maths::min(float a, float b) { return (a>b)?b:a; }

double Maths::Root(double num)
{
    double error = 10e-6;
    double toRoot = num;

    while ((toRoot - num / toRoot) > error)
    {
        toRoot = (toRoot + num / toRoot) / 2;
    }
    return toRoot;
}

float Maths::DTR(float Degree)
{
    return (Degree * (PI/180));
}

float Maths::RTD(float Radian)
{
    return (Radian * (180/PI));
}

void Maths::Range(float &victim, float max)
{
    victim = (1/victim) * max;
}

Vector2 Maths::ConvertTorlVector2(V2 toConvert)
{
    return Vector2{(float)toConvert.x,(float)toConvert.y};
}

V2 Maths::ConvertToV2(Vector2 toConvert)
{
    return V2(toConvert.x,toConvert.y);
}

float Maths::RelativeX(float xPixel)
{
    return 0;
}

float Maths::RelativeY(float yPixel)
{
    return 0;
}
