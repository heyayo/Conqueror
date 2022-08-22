#ifndef PROTOTYPE_SAVESTATE_HPP
#define PROTOTYPE_SAVESTATE_HPP

#include "Entity.hpp"

class SaveState
{
Entity* toSave;
std::string saveName;

public:
    SaveState(Entity* saving, const char* sn);

    const char* GetName();
    Entity* GetEntity();
};


#endif
