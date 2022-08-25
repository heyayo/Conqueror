#include "raylib.h"
#include "Game.hpp"

int main()
{
    InitWindow(GetScreenWidthC(), GetScreenHeightC(),"CONQUERORS DUNGEON");
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
