#include "Math.hpp"
#include <random>

void InitRandom(unsigned seed)
{
    srand(seed);
}

double Root(double num)
{
    double error = 10e-6;
    double toRoot = num;

    while ((toRoot - num / toRoot) > error)
    {
        toRoot = (toRoot + num / toRoot) / 2;
    }
    return toRoot;
}

int RandIntRange(int min, int max)
{
    return (rand() % (max-min)) + min;
}
