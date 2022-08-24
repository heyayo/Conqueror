#ifndef PROTOTYPE_LEVELMID1_HPP
#define PROTOTYPE_LEVELMID1_HPP

#include "Scene.hpp"

class Levelmid1 : public Scene
{

public:

    void LoadScene() override;
    void SceneUpdate() override;
    void Collision() override;
};


#endif
