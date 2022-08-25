#include "Game.hpp"
#include "TestScene.hpp"
#include "MainMenu.hpp"
#include "LevelOne.hpp"
#include "LevelTwo.hpp"
#include "LevelFive.hpp"
#include "classChoose.hpp"
#include "LevelFour.h"
#include "LevelThree.h"
#include "Levelmid1.hpp"

Scene* currentScene;
Scene* scenes[SCENEMAX];
PLAYERCLASS chosen = ARCHER;
SaveState save;

void GenerateScenes()
{
    scenes[TESTSCENE] = new TestScene;
    scenes[CLASSCHOOSE] = new classChoose;
    scenes[MAINMENU] = new MainMenu;
    scenes[LEVELONE] = new LevelOne;
    scenes[LEVELTWO] = new LevelTwo;
    scenes[LEVELTHREE] = new LevelThree;
    scenes[LEVELFIVE] = new LevelFive;
    scenes[LEVELFOUR] = new LevelFour;
    scenes[LEVELMID1] = new Levelmid1;
    currentScene = scenes[LEVELTWO];
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

PLAYERCLASS GetPlayersClass()
{
    return chosen;
}

void SetPlayersClass(PLAYERCLASS choose)
{
    chosen = choose;
}

void CreateSave(SaveState newSave)
{
    save = newSave;
}

SaveState LoadSave()
{
    return save;
}
