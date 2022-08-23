#ifndef PROTOTYPE_DEADSOUL_HPP
#define PROTOTYPE_DEADSOUL_HPP

#include "Physical.hpp"

class DeadSoul : public Physical
{
private:
    const char* message;
    bool speaking = false;

public:
    DeadSoul(const char* msg);

    void Start() override;
    void Update() override;

    bool isSpeaking();
};


#endif
