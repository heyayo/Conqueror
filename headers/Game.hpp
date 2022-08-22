#ifndef PROTOTYPE_GAME_HPP
#define PROTOTYPE_GAME_HPP

#include "Scene.hpp"

// ADD SCENE NAMES BELOW
enum SCENES
{
    TESTSCENE,
    MAINMENU,
    LEVELONE,
    SCENEMAX
};
// ADD SCENE NAMES ABOVE

Scene* GetCurrentScene();

void LoadScene(Scene* next);
void LoadSceneByEnum(SCENES enumer);
void RunScene();
void Close();
void GenerateScenes();

#endif
