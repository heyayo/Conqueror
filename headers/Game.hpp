#ifndef PROTOTYPE_GAME_HPP
#define PROTOTYPE_GAME_HPP

#include "Scene.hpp"
#include "SaveState.hpp"

// ADD SCENE NAMES BELOW
enum SCENES
{
    TESTSCENE,
    MAINMENU,
    LEVELONE,
    LEVELTWO,
    LEVELFIVE,
    LEVELTHREE,
    CLASSCHOOSE,
    LEVELFOUR,
    LEVELMID1,
    SCENEMAX
};
// ADD SCENE NAMES ABOVE

Scene* GetCurrentScene();

void LoadScene(Scene* next);
void LoadSceneByEnum(SCENES enumer);
void RunScene();
void Close();
void GenerateScenes();

void LoadSave(Physical* en, const char* sn);
SaveState GetSaveByName(const char* name);
SaveState GetSaveByIndex(unsigned index);

#endif
