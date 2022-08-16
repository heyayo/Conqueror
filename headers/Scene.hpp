#ifndef PROTOTYPE_SCENE_HPP
#define PROTOTYPE_SCENE_HPP

#include "raylib.h"
#include <vector>
#include "Entity.hpp"

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

    virtual void SceneRun() = 0;
};


#endif
