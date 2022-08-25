#ifndef PROTOTYPE_GAME_HPP
#define PROTOTYPE_GAME_HPP

#include "Scene.hpp"

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

struct SaveState
{
    float health;
    float damage;
    float speed;
    float armour;
    unsigned JournalCount;
    SCENES currentLevel;
};

enum PLAYERCLASS
{
    ARCHER,
    WARRIOR,
    WIZARD,
    ASSASSIN
};

Scene* GetCurrentScene();

void LoadScene(Scene* next);
void LoadSceneByEnum(SCENES enumer);
void RunScene();
void Close();
void GenerateScenes();

void CreateSave(SaveState newSave);
SaveState LoadSave();

PLAYERCLASS GetPlayersClass();
void SetPlayersClass(PLAYERCLASS choose);

#endif
