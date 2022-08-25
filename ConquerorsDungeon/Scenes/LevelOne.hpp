#ifndef PROTOTYPE_LEVELONE_HPP
#define PROTOTYPE_LEVELONE_HPP

#include "Scene.hpp"

class LevelOne : public Scene
{

public:

    void LoadScene() override;
    void SceneUpdate() override;
    void Collision() override;
};


#endif
