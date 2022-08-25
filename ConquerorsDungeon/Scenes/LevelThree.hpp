#ifndef PROTOTYPE_LEVELTHREE_HPP
#define PROTOTYPE_LEVELTHREE_HPP

#include "Scene.hpp"

class LevelThree : public Scene
{

public:

    void LoadScene() override;
    void SceneUpdate() override;
    void Collision() override;
};

#endif
