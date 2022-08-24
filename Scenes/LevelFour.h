#ifndef PROTOTYPE_LEVELTWO_HPP
#define PROTOTYPE_LEVELTWO_HPP

#include "Scene.hpp"

class LevelFour : public Scene
{

public:
    void LoadScene() override;
    void SceneUpdate() override;
    void Collision() override;
};

#endif
