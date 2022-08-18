#include <iostream>
#include "raylib.h"
#include "TestScene.hpp"
#include "Game.hpp"
#include "MainMenu.hpp"

int main()
{
    InitWindow(CONFIG::GetScreenWidth(), CONFIG::GetScreenHeight(),"TESTWINDOW");
    Init();

    LoadSceneByEnum(MAINMENU);

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
