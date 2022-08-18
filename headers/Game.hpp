#ifndef PROTOTYPE_GAME_HPP
#define PROTOTYPE_GAME_HPP

#include "Scene.hpp"

// ADD SCENE NAMES BELOW
enum SCENES
{
    TESTSCENE,
    MAINMENU,
    SCENEMAX
};
// ADD SCENE NAMES ABOVE

Scene* GetCurrentScene();

void LoadScene(Scene* next);
void LoadSceneByEnum(SCENES enumer);
void RunScene();
void Close();
void Init();

Vector2 ConvertTorlVector2(V2 toConvert);
V2 ConvertToV2(Vector2 toConvert);

namespace CONFIG
{
    int GetScreenWidth();
    int GetScreenHeight();
    V2 GetScreenResolution();
    V2 GetScreenCenter();
}

#endif
