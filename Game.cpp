#include "Game.hpp"
#include "TestScene.hpp"
#include "MainMenu.hpp"

Scene* currentScene;
Scene* scenes[SCENEMAX];

void InitScenes()
{
    scenes[TESTSCENE] = new TestScene;
    scenes[MAINMENU] = new MainMenu;
}

Scene* GetCurrentScene()
{
    return currentScene;
}

void LoadScene(Scene *next)
{
    currentScene = next;
}

void LoadSceneByEnum(SCENES enumer)
{
    currentScene = scenes[enumer];
}

void RunScene()
{
    currentScene->SceneUpdate();
}

void Close()
{
    delete currentScene;
}
