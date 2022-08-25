#ifndef PROTOTYPE_WINSTAGE_HPP
#define PROTOTYPE_WINSTAGE_HPP

#include "Scene.hpp"

class WinStage : public Scene
{
public:
    void LoadScene() override;
    void SceneUpdate() override;
    void Collision() override;
};


#endif
