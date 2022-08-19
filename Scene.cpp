#include "Scene.hpp"
#include "Physical.hpp"

std::vector<Entity *> *Scene::GetEntities(){return &Entities;}
std::vector<UIElement *> *Scene::GetUIElements(){return &UICollection;}

Scene::Scene()
{
    Image img = GenImageColor(GetScreenWidth(),GetScreenHeight(),WHITE);
    bgTex = LoadTextureFromImage(img);
    UnloadImage(img);
    sceneSize = V2(1920,1080);
    cameraSize = V2(1920,1080);
    cameraPos = V2();
    SetScreenDelta(cameraSize);
}

void Scene::SetBG(const char* bgimgsrc, V2 resize)
{
    UnloadTexture(bgTex);
    Image bgimg = LoadImage(bgimgsrc);
    ImageResize(&bgimg,resize.x,resize.y);
    bgTex = LoadTextureFromImage(bgimg);
    UnloadImage(bgimg);
}

void Scene::SetBG(const char *bgimgsrc)
{
    UnloadTexture(bgTex);
    Image img = LoadImage(bgimgsrc);
    ImageResize(&img, img.width,img.height);
    bgTex = LoadTextureFromImage(img);
}

void Scene::AddEntity(Entity *add)
{
    Entities.push_back(add);
    add->Start();
}

void Scene::SceneDraw()
{
    DrawTexturePro(bgTex,
                   Rectangle{cameraPos.x,cameraPos.y,cameraSize.x,cameraSize.y},
                   {0,0,(float)GetScreenWidth(),(float)GetScreenHeight()},
                    {0,0},
                    0,
                    WHITE);
    for (int i = 0; i < Entities.size(); i++)
    {
        Entity* temp = Entities[i];
        temp->Draw();
        temp->Update();
    }
    for (int i = 0; i < UICollection.size(); i++)
    {
        UIElement* temp = UICollection[i];
        temp->Draw();
        temp->Update();
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

bool Scene::CalculateCollisionBorder(Physical *body)
{
    V2 bPos = body->GetPosition();
    V2 bSize = body->GetColSize();

    return
    ((bPos.x + bSize.x >= GetScreenWidthDeltad()) ||
    (bPos.x - bSize.x <= 0) ||
    (bPos.y + bSize.y >= GetScreenHeightDeltad()) ||
    (bPos.y - bSize.y <= 0));
}

Entity* Scene::GetEntityByIndex(unsigned int index)
{
    return Entities[index];
}

Physical *Scene::GetPhysicsByIndex(unsigned int index)
{
    return static_cast<Physical*>(Entities[index]);
}

Scene::~Scene()
{
    for (int i = 0; i < Entities.size(); i++)
        if (Entities[i] != nullptr)
            delete Entities[i];
    Entities.clear();
    for (int i = 0; i < UICollection.size(); i++)
        if (UICollection[i] != nullptr)
            delete UICollection[i];
    UICollection.clear();
}

bool Scene::Kill(Entity *object)
{
    for (int i = 0; i < Entities.size(); i++)
    {
        if (Entities[i] == object)
        {
            delete object;
            Entities.erase(Entities.begin()+i);
            return true;
        }
    }
    return false;
}

void Scene::KillByIndex(unsigned int index)
{
    delete Entities[index];
    Entities.erase(Entities.begin()+index);
}

std::vector<Entity*> Scene::GetPhysicsByGroupID(unsigned int ID)
{
    std::vector<Entity*> list;
    for (int i = 0; i < Entities.size(); i++)
    {
        if (Entities[i]->GetID() == ID)
            list.push_back(Entities[i]);
    }
    return list;
}

std::vector<Entity*> Scene::GetPhysicsByGroup(const char *name)
{
    std::vector<Entity*> list;
    for (int i = 0; i < Entities.size(); i++)
    {
        if (Entities[i]->GetName() == name)
            list.push_back(Entities[i]);
    }
    return list;
}

void Scene::SetBG(Color color)
{
    UnloadTexture(bgTex);
    Image img = GenImageColor(sceneSize.x,sceneSize.y,color);
    bgTex = LoadTextureFromImage(img);
    UnloadImage(img);
}

void Scene::AddUI(UIElement *add)
{
    UICollection.push_back(add);
    add->Start();
}

void Scene::SetSceneSize(V2 newSize)
{
    sceneSize = newSize;
}

void Scene::SetCameraSize(V2 newSize)
{
    cameraSize = newSize;
    SetCameraSize(cameraSize);
}

void Scene::SetCameraPos(V2 newPos)
{
    cameraPos = newPos;
}
