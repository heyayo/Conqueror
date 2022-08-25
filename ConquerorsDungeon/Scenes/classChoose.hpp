#ifndef PROTOTYPE_CLASSCHOOSE_HPP
#define PROTOTYPE_CLASSCHOOSE_HPP

#include "Scene.hpp"

class classChoose : public Scene
{
public:

    void LoadScene() override;
    void SceneUpdate() override;
    void Collision() override;
};


#endif
