#ifndef PROTOTYPE_MAINMENU_HPP
#define PROTOTYPE_MAINMENU_HPP

#include "Scene.hpp"

class MainMenu : public Scene
{
public:
    MainMenu();

    void SceneUpdate() override;
    void Collision() override;
};


#endif
