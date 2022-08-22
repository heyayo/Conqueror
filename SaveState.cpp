#include "SaveState.hpp"

SaveState::SaveState(Entity *saving, const char *sn) : toSave(saving), saveName(sn){}

const char *SaveState::GetName()
{
    return saveName.c_str();
}

Entity *SaveState::GetEntity()
{
    return toSave;
}
