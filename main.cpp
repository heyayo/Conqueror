#include "raylib.h"
#include "Game.hpp"

int main()
{
    InitWindow(GetScreenWidthC(), GetScreenHeightC(),"TESTWINDOW");
    InitScenes();

    LoadSceneByEnum(TESTSCENE);

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
