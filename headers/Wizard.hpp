#ifndef PROTOTYPE_WIZARD_HPP
#define PROTOTYPE_WIZARD_HPP

#include "Character.hpp"

class Wizard : public Character
{
public:
    Wizard();

    void Start() override;
    void Update() override;
};

#endif