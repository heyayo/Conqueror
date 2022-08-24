#ifndef PROTOTYPE_LEVELFOUR_HPP
#define PROTOTYPE_LEVELFOUR_HPP

#include "Scene.hpp"

class LevelFour : public Scene
{

public:
    void LoadScene() override;
    void SceneUpdate() override;
    void Collision() override;
};

#endif
