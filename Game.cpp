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

