#include <iostream>
#include "raylib.h"
#include "Entity.hpp"
#include "Maths.hpp"

static const int width = 800;
static const int height = 600;
static const int cwidth = width/2;
static const int cheight = height/2;

int main()
{
    InitWindow(width,height,"TESTWINDOW");

    Vector2 velocity = {0,0};

    Entity player("sprites/hero.png", 128,128);
    Entity other("sprites/other.png", 128,128);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("TEST TEXT",cwidth,cheight,18,BLACK);
        player.Draw();
        other.Draw();
        EndDrawing();
        velocity.x += IsKeyDown(KEY_D);
        velocity.x -= IsKeyDown(KEY_A);
        velocity.y += IsKeyDown(KEY_S);
        velocity.y -= IsKeyDown(KEY_W);
        player.Move(velocity);
        Maths::ShiftTowards(velocity.x, 0.f, 0.2f);
        Maths::ShiftTowards(velocity.y, 0.f, 0.2f);
    }
    CloseWindow();
}
