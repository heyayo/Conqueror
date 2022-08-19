#include "Config.hpp"

int ScreenWidth = 1280;
int ScreenHeight = 720;
float ScreenDeltaX = 1;
float ScreenDeltaY = 1;

V2 GetScreenResolution()
{
    return V2(ScreenWidth,ScreenHeight);
}

V2 GetScreenCenter()
{
    V2 divisor(2,2);
    return GetScreenResolution() / divisor;
}

int GetScreenWidthC()
{
    return ScreenWidth;
}

int GetScreenHeightC()
{
    return ScreenHeight;
}

void SetScreenDelta(V2 camSize)
{
    V2 delta = GetScreenResolution()/camSize;
    ScreenDeltaX = delta.x;
    ScreenDeltaY = delta.y;
}

V2 GetScreenDelta()
{
    return V2(ScreenDeltaX,ScreenDeltaY);
}

float DeltarizeX(float xe)
{
    return xe*ScreenDeltaX;
}

float DeltarizeY(float ye)
{
    return ye*ScreenDeltaY;
}

float GetScreenDeltaY()
{
    return ScreenDeltaX;
}

float GetScreenDeltaX()
{
    return ScreenDeltaY;
}

V2 GetScreenResolutionDeltad()
{
    V2 scrRes = GetScreenResolution();
    V2 delta = GetScreenDelta();
    return scrRes * delta;
}

float GetScreenWidthDeltad()
{
    return ScreenWidth/ScreenDeltaX;
}

float GetScreenHeightDeltad()
{
    return ScreenHeight/ScreenDeltaY;
}


