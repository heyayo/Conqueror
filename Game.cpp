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

V2 ConvertToV2(Vector2 toConvert)
{
    return V2(toConvert.x,toConvert.y);
}

