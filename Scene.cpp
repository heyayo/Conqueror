#include "Scene.hpp"
#include "Physical.hpp"

std::vector<Entity *> *Scene::GetEntities()
{
    return &Entities;
}

Scene::Scene()
{
    bgColor = WHITE;
}

void Scene::SetBGColor(Color bgc)
{
    bgColor = bgc;
}

void Scene::AddEntity(Entity *add)
{
    Entities.push_back(add);
}

void Scene::SceneDraw()
{
    ClearBackground(bgColor);
    for (int i = 0; i < Entities.size(); i++)
    {
        Entity* temp = Entities[i];
        temp->Update();
        temp->Draw();
    }
}

bool Scene::CalculateCollisionsBetween(Physical *bodyone, Physical *bodytwo)
{
    V2 aPos = bodyone->GetPosition();
    V2 bPos = bodytwo->GetPosition();
    V2 aDist = bodyone->GetColSize();
    V2 bDist = bodytwo->GetColSize();

    int xDist = aDist.x + bDist.x;
    int yDist = aDist.y + bDist.y;
    int trueXDist = abs(aPos.x - bPos.x);
    int trueYDist = abs(aPos.y - bPos.y);

    return
    (xDist >= trueXDist && yDist >= trueYDist);
}

Entity* Scene::GetEntityByIndex(unsigned int index)
{
    return Entities[index];
}

Physical *Scene::GetPhysicsByIndex(unsigned int index)
{
    return static_cast<Physical*>(Entities[index]);
}
