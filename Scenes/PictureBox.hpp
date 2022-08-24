#ifndef PROTOTYPE_PICTUREBOX_HPP
#define PROTOTYPE_PICTUREBOX_HPP

#include "UiElement.hpp"

class PictureBox : public UIElement
{
public:
    enum ORIENTATION
    {
        UP,
        DOWN
    };

private:
    std::string caption = "";
    float fontSize = 18;
    float spacing = 1;
    Font font = LoadFont("fonts/caveat.ttf");
    ORIENTATION orient = DOWN;
    V2 textPos;
    Vector2 textOffset;
    Color textColor = WHITE;

public:
    PictureBox(const char* imgsrc, V2 size);
    PictureBox(const char* imgsrc, int xs, int ys);

    void SetCaption(const char* newCap);
    void SetFontSize(float newFS);
    void SetSpacing(float newSpace);
    void SetOrientation(ORIENTATION ori);
    void SetTextColor(Color newC);

    void Start() override;
    void Update() override;
};


#endif
