#ifndef PROTOTYPE_SCENE_HPP
#define PROTOTYPE_SCENE_HPP

#include "raylib.h"
#include <vector>
#include "UiElement.hpp"
#include "Physical.hpp"
#include "Config.hpp"
#include "Actor.hpp"

class Scene
{
    std::vector<Physical*> Entities;
    std::vector<UIElement*> UICollection;
    Texture2D bgTex;

protected:
    std::vector<Physical *> * GetPhysicals();
    std::vector<UIElement*>* GetUIElements();
    V2 sceneSize;
    V2 cameraSize;
    V2 cameraPos;

public:
    Scene();
    virtual ~Scene();

    void SetBG(const char* bgimgsrc, V2 resize);
    void SetBG(const char* bgimgsrc);
    void SetBG(Color color);
    void SetSceneSize(V2 newSize);
    void SetCameraSize(V2 newSize);
    void SetCameraPos(V2 newPos);
    void SceneDraw();
    void UnloadScene();

    void AddPhysical(Physical *add);
    bool CalculateCollisionsBetween(Physical *bodyone, Physical *bodytwo);
    bool CalculateCollisionBorder(Physical* body);
    bool Kill(Entity* object);
    void KillByIndex(unsigned index);

    Physical* GetPhysicsByIndex(unsigned index);
    Physical* GetPhysicsByName(const char* name);
    std::vector<Physical *> GetPhysicsByGroupID(unsigned ID);
    std::vector<Physical *> GetPhysicsByGroup(const char* name);
    std::vector<Actor*> GetActorsByGroup(const char* name);

    void AddUI(UIElement* add);

    virtual void LoadScene() = 0;
    virtual void SceneUpdate() = 0;
    virtual void Collision() = 0;
};


#endif
