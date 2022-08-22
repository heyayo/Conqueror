#ifndef PROTOTYPE_DEADSOUL_HPP
#define PROTOTYPE_DEADSOUL_HPP

#include "Physical.hpp"

class DeadSoul : public Physical
{
public:
    enum TEXTORIENTATION
    {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

private:
    const char* message;
    bool speaking = false;
    TEXTORIENTATION orient = LEFT;

public:
    DeadSoul(const char* msg);

    void Start() override;
    void Update() override;

    void SetOrientation(TEXTORIENTATION ori);

    TEXTORIENTATION GetOrientation();
    bool isSpeaking();
};


#endif
