#include "raylib.h"
#include "Game.hpp"

int main()
{
    InitWindow(GetScreenWidthC(), GetScreenHeightC(),"CONQUERORS DUNGEON");
#ifdef _WIN32
    ToggleFullscreen();
#endif
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
