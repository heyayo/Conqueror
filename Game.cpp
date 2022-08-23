#include "Game.hpp"
#include "TestScene.hpp"
#include "MainMenu.hpp"
#include "LevelOne.hpp"
#include "LevelTwo.hpp"
#include "LevelFive.hpp"
Scene* currentScene;
Scene* scenes[SCENEMAX];
std::vector<SaveState> saves;

void GenerateScenes()
{
    scenes[TESTSCENE] = new TestScene;
    scenes[MAINMENU] = new MainMenu;
    scenes[LEVELONE] = new LevelOne;
    scenes[LEVELTWO] = new LevelTwo;
    scenes[LEVELFIVE] = new LevelFive;

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

void LoadSave(Entity *en, const char *sn)
{
    SaveState temp;
    temp.toSave = en->MakeCopy();
    temp.saveName = sn;
    saves.push_back(temp);
}

SaveState GetSaveByName(const char *name)
{
    for (auto i : saves)
    {
        if (i.saveName == name)
            return i;
    }
    return SaveState{nullptr,"NULL"};
}

SaveState GetSaveByIndex(unsigned int index)
{
    if (index > saves.size())
        return SaveState{nullptr,"NULL"};
    return saves[index];
}
