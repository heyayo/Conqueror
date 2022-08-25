#include "Scene.hpp"
#include "Physical.hpp"

std::vector<Physical *> * Scene::GetPhysicals(){return &Entities;}
std::vector<UIElement *> *Scene::GetUIElements(){return &UICollection;}

Scene::Scene()
{
    sceneSize = V2(1920,1080);
    cameraSize = V2(1920,1080);
    cameraPos = V2();
    SetScreenDelta(cameraSize);
}

Scene::~Scene()
{

}

void Scene::UnloadScene()
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

void Scene::SetBG(Color color)
{
    UnloadTexture(bgTex);
    Image img = GenImageColor(sceneSize.x,sceneSize.y,color);
    bgTex = LoadTextureFromImage(img);
    UnloadImage(img);
}

void Scene::AddPhysical(Physical *add)
{
    Entities.push_back(add);
    add->Start();
}

void Scene::AddUI(UIElement *add)
{
    UICollection.push_back(add);
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
        temp->Update();
        temp->Draw();
    }
    for (int i = 0; i < UICollection.size(); i++)
    {
        UIElement* temp = UICollection[i];
        if (temp->GetVisibility())
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

Physical *Scene::GetPhysicsByIndex(unsigned int index)
{
    if (index > Entities.size())
        return nullptr;
    return Entities[index];
}

Physical *Scene::GetPhysicsByName(const char *name)
{
    for (int i = 0; i < Entities.size(); i++)
    {
        if (Entities[i]->GetName() == name)
            return Entities[i];
    }
    return nullptr;
}

bool Scene::Kill(Entity *object)
{
    if (object == nullptr)
        false;
    for (int i = 0; i < Entities.size(); i++)
    {
        if (Entities[i] == object)
        {
            delete object;
            object = nullptr;
            Entities.erase(Entities.begin()+i);
            return true;
        }
    }
    return false;
}

bool Scene::RemoveUI(UIElement *ui)
{
    if (ui == nullptr)
        return false;
    for (int i = 0; i < UICollection.size(); i++)
    {
        if (UICollection[i] == ui)
        {
            delete ui;
            ui = nullptr;
            UICollection.erase(UICollection.begin()+i);
            return true;
        }
    }
    return false;
}

void Scene::KillByIndex(unsigned int index)
{
    if (index > Entities.size())
        return;
    delete Entities[index];
    Entities.erase(Entities.begin()+index);
}

std::vector<Physical *> Scene::GetPhysicsByGroupID(unsigned int ID)
{
    std::vector<Physical*> list;
    for (int i = 0; i < Entities.size(); i++)
    {
        if (Entities[i]->GetID() == ID)
            list.push_back(Entities[i]);
    }
    return list;
}

std::vector<Physical *> Scene::GetPhysicsByGroup(const char *name)
{
    std::vector<Physical*> list;
    for (int i = 0; i < Entities.size(); i++)
    {
        if (Entities[i]->GetGroupName() == name)
            list.push_back(Entities[i]);
    }
    return list;
}

std::vector<Actor *> Scene::GetActorsByGroup(const char *name)
{
    std::vector<Actor*> list;
    for (auto actors : Entities)
    {
        if (actors->GetTypeOfEntity() == Entity::ACTOR && actors->GetGroupName() == name)
            list.push_back(dynamic_cast<Actor*>(actors));
    }
    return list;
}

void Scene::SetSceneSize(V2 newSize)
{
    sceneSize = newSize;
}

void Scene::SetCameraSize(V2 newSize)
{
    cameraSize = newSize;
}

void Scene::SetCameraPos(V2 newPos)
{
    cameraPos = newPos;
}

Actor *Scene::GetActorByName(const char *name)
{
    for (auto i : Entities)
    {
        if (i->GetName() == name && i->GetTypeOfEntity() == Entity::ACTOR)
            return dynamic_cast<Actor*>(i);
    }
    return nullptr;
}

UIElement *Scene::GetUIElementByName(const char *name)
{
    for (auto ui : UICollection)
        if (ui->GetName() == name)
            return ui;
    return nullptr;
}


