#include "Game.hpp"

Scene* currentScene;

Scene* GetCurrentScene()
{
    return currentScene;
}

void LoadScene(Scene *next)
{
    currentScene = next;
}

void RunScene()
{
    currentScene->SceneUpdate();
}

void Close()
{
    delete currentScene;
}

Vector2 ConvertTorlVector2(V2 toConvert)
{
    return Vector2{(float)toConvert.x,(float)toConvert.y};
}

