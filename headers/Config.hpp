#ifndef PROTOTYPE_CONFIG_HPP
#define PROTOTYPE_CONFIG_HPP

#include "V2.hpp"

int GetScreenWidthC();
int GetScreenHeightC();
float GetScreenDeltaX();
float GetScreenDeltaY();
float GetScreenWidthDeltad();
float GetScreenHeightDeltad();
V2 GetScreenResolution();
V2 GetScreenResolutionDeltad();
V2 GetScreenCenter();
V2 GetScreenDelta();

void SetScreenDelta(V2 camSize);

float DeltarizeX(float xe);
float DeltarizeY(float ye);
float ODeltarizeX(float xe);
float ODeltarizeY(float ye);

#endif