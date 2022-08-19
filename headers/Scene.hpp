#ifndef PROTOTYPE_SCENE_HPP
#define PROTOTYPE_SCENE_HPP

#include "raylib.h"
#include <vector>
#include "UiElement.hpp"
#include "Physical.hpp"
#include "Config.hpp"

class Scene
{
    std::vector<Entity*> Entities;
    std::vector<UIElement*> UICollection;
    Texture2D bgTex;

protected:
    std::vector<Entity*>* GetEntities();
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

    void AddEntity(Entity* add);
    bool CalculateCollisionsBetween(Physical *bodyone, Physical *bodytwo);
    bool CalculateCollisionBorder(Physical* body);
    bool Kill(Entity* object);
    void KillByIndex(unsigned index);

    Entity* GetEntityByIndex(unsigned index);
    Physical* GetPhysicsByIndex(unsigned index);
    std::vector<Entity*> GetPhysicsByGroupID(unsigned ID);
    std::vector<Entity*> GetPhysicsByGroup(const char* name);

    void AddUI(UIElement* add);

    virtual void SceneUpdate() = 0;
    virtual void Collision() = 0;
};


#endif
