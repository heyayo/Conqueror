#ifndef PROTOTYPE_GAME_HPP
#define PROTOTYPE_GAME_HPP

#include "Scene.hpp"

Scene* GetCurrentScene();

void LoadScene(Scene* next);
void RunScene();
void Close();

Vector2 ConvertTorlVector2(V2 toConvert);

#endif
