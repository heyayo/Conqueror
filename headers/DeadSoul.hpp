#ifndef PROTOTYPE_DEADSOUL_HPP
#define PROTOTYPE_DEADSOUL_HPP

#include "Physical.hpp"

class DeadSoul : public Physical
{
private:
    std::string* msgList;
    unsigned count;
    bool speaking = false;

public:
    DeadSoul(std::string* list, unsigned c);

    void Start() override;
    void Update() override;

    bool isSpeaking();
};


#endif
