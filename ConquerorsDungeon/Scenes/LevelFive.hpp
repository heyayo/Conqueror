#ifndef PROTOTYPE_LEVELFIVE_HPP
#define PROTOTYPE_LEVELFIVE_HPP

#include "Scene.hpp"

class LevelFive : public Scene
{

public:

    void LoadScene() override;
    void SceneUpdate() override;
    void Collision() override;
};

#endif