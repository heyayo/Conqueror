#ifndef PROTOTYPE_DOOR_HPP
#define PROTOTYPE_DOOR_HPP

#include "Game.hpp"

class Door : public Physical
{
    SCENES toLoad = MAINMENU;
public:
    Door();

    void Redirect(SCENES leadTo);

    void Start() override;
    void Update() override;
};


#endif
