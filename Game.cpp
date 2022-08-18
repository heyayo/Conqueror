#include "Game.hpp"
#include "TestScene.hpp"
#include "MainMenu.hpp"

Scene* currentScene;
int ScreenWidth = 1920;
int ScreenHeight = 1080;
Scene* scenes[SCENEMAX];

void Init()
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

Vector2 ConvertTorlVector2(V2 toConvert)
{
    return Vector2{(float)toConvert.x,(float)toConvert.y};
}

V2 ConvertToV2(Vector2 toConvert)
{
    return V2(toConvert.x,toConvert.y);
}

V2 CONFIG::GetScreenResolution()
{
    return V2(ScreenWidth,ScreenHeight);
}

V2 CONFIG::GetScreenCenter()
{
    V2 divisor(2,2);
    return GetScreenResolution() / divisor;
}

int CONFIG::GetScreenWidth()
{
    return ScreenWidth;
}

int CONFIG::GetScreenHeight()
{
    return ScreenHeight;
}
