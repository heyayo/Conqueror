#ifndef PROTOTYPE_SCENE_HPP
#define PROTOTYPE_SCENE_HPP

#include "raylib.h"
#include <vector>
#include "Entity.hpp"
#include "Physical.hpp"

class Scene
{
    std::vector<Entity*> Entities;
    Color bgColor;

protected:
    std::vector<Entity*>* GetEntities();
    void AddEntity(Entity* add);

public:
    Scene();

    void SetBGColor(Color bgc);
    void SceneDraw();
    bool CalculateCollisionsBetween(Physical *bodyone, Physical *bodytwo);

    Entity* GetEntityByIndex(unsigned index);

    Physical* GetPhysicsByIndex(unsigned index);

    virtual void SceneRun() = 0;
    virtual void Collision() = 0;
};


#endif
