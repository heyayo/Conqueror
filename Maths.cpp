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
