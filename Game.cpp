#include "Game.hpp"
#include "TestScene.hpp"
#include "MainMenu.hpp"

Scene* currentScene;
Scene* scenes[SCENEMAX];

void GenerateScenes()
{
    scenes[TESTSCENE] = new TestScene;
    scenes[MAINMENU] = new MainMenu;

    currentScene = scenes[TESTSCENE];
    currentScene->LoadScene();
}

Scene* GetCurrentScene()
{
    return currentScene;
}

void LoadScene(Scene *next)
{
    currentScene->UnloadScene();
    currentScene = next;
    currentScene->LoadScene();
}

void LoadSceneByEnum(SCENES enumer)
{
    currentScene->UnloadScene();
    currentScene = scenes[enumer];
    currentScene->LoadScene();
}

void RunScene()
{
    currentScene->SceneUpdate();
    currentScene->SceneDraw();
    currentScene->Collision();
}

void Close()
{
    for (int i = 0; i < SCENEMAX; i++)
        delete scenes[i];
}

