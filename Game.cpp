#include "Game.hpp"
#include "TestScene.hpp"
#include "MainMenu.hpp"
#include "LevelOne.hpp"

Scene* currentScene;
Scene* scenes[SCENEMAX];
std::vector<SaveState> saves;

void GenerateScenes()
{
    scenes[TESTSCENE] = new TestScene;
    scenes[MAINMENU] = new MainMenu;
    scenes[LEVELONE] = new LevelOne;

    currentScene = scenes[LEVELONE];
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

void LoadSave(Entity *en, const char *sn)
{
    saves.push_back(SaveState(en,sn));
}

SaveState GetSaveByName(const char *name)
{
    for (auto i : saves)
    {
        if (i.GetName() == name)
            return i;
    }
}

SaveState GetSaveByIndex(unsigned int index)
{
    if (index > saves.size())
        return SaveState(nullptr,"NULL");
    return saves[index];
}
