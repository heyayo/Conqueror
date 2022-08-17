#include <iostream>
#include "raylib.h"
#include "TestScene.hpp"
#include "Game.hpp"

static const int width = 1920;
static const int height = 1080;
static const int cwidth = width/2;
static const int cheight = height/2;

int main()
{
    InitWindow(width,height,"TESTWINDOW");

    TestScene* testScene = new TestScene;
    LoadScene(testScene);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        RunScene();
        DrawText("MASSIVE TEXT",cwidth,cheight,45,BLACK);
        EndDrawing();
    }
    Close();
    CloseWindow();
}
