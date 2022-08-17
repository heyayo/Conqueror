#ifndef PROTOTYPE_TESTSCENE_HPP
#define PROTOTYPE_TESTSCENE_HPP

#include "Scene.hpp"

class TestScene : public Scene
{
public:
    TestScene();

    void SceneUpdate() override;
    void Collision() override;
};


#endif
