#ifndef PROTOTYPE_SCENE_HPP
#define PROTOTYPE_SCENE_HPP

#include "raylib.h"
#include <vector>
#include "Entity.hpp"
#include "Physical.hpp"

class Scene
{
    std::vector<Entity*> Entities;
    Rectangle bg;
    Texture2D bgTex;

protected:
    std::vector<Entity*>* GetEntities();

public:
    Scene();
    virtual ~Scene();

    void SetBG(Texture2D bgimg);
    void SetBG(const char* bgimgsrc);
    void SetBG(Color color);

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

    virtual void SceneUpdate() = 0;
    virtual void Collision() = 0;
};


#endif
