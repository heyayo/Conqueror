#include "Scene.hpp"

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
        temp->Draw();
        temp->Update();

    }
}
