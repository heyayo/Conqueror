#include "raylib.h"
#include "Game.hpp"

int main()
{
    InitWindow(GetScreenWidthC(), GetScreenHeightC(),"TESTWINDOW");
    GenerateScenes();

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        RunScene();
        EndDrawing();
    }
    Close();
    CloseWindow();
}
