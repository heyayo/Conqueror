#include "classChoose.hpp"
#include "TextBox.hpp"
#include "Game.hpp"
#include "PictureBox.hpp"

TextBox* Title1;
PictureBox* c[4];

void classChoose::SceneUpdate()
{
}

void classChoose::Collision()
{
    for (auto i : c)
    {
        if (i->CalculateMouseCollision())
        {
            i->SetTextColor(BLUE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                LoadSceneByEnum(LEVELONE);
        }
        else
            i->SetTextColor(WHITE);
    }
}

void classChoose::LoadScene()
{
    SetBG("SceneBG/mainmenu.png", V2(1920, 1080));

    std::string mT("CHOOSE YOUR CLASS");
    Title1 = new TextBox(&mT, 1);
    Title1->SetTextColor(BLACK);
    Title1->SetBoxColor(GOLD);
    Title1->SetAlignment(TextBox::CENTER);
    Title1->SetFontSize(120);
    Title1->SetPadding(V2(100, 100));
    V2 offset(0, 300);
    Title1->SetPosition(GetScreenCenter() + offset);

    V2 classOffset(300,0);
    c[0] = new PictureBox("sprites/Archer move.png",V2(256,256));
    c[0]->SetPosition(GetScreenCenter() - classOffset - classOffset);
    c[0]->SetFontSize(28);
    c[0]->SetSpacing(10);
    c[0]->SetCaption("ARCHER");
    c[0]->SetOrientation(PictureBox::DOWN);

    c[1] = new PictureBox("sprites/warrior move.png",V2(256,256));
    c[1]->SetPosition(GetScreenCenter() - classOffset);
    c[1]->SetFontSize(28);
    c[1]->SetSpacing(10);
    c[1]->SetCaption("WARRIOR");
    c[1]->SetOrientation(PictureBox::DOWN);

    c[2] = new PictureBox("sprites/wizard move.png",V2(256,256));
    c[2]->SetPosition(GetScreenCenter() + classOffset);
    c[2]->SetFontSize(28);
    c[2]->SetSpacing(10);
    c[2]->SetCaption("WIZARD");
    c[2]->SetOrientation(PictureBox::DOWN);

    c[3] = new PictureBox("sprites/hughjackman.png",V2(256,256));
    c[3]->SetPosition(GetScreenCenter() + classOffset + classOffset);
    c[3]->SetFontSize(28);
    c[3]->SetSpacing(10);
    c[3]->SetCaption("HUGH JACKMAN");
    c[3]->SetOrientation(PictureBox::DOWN);

    AddUI(Title1);
    for (auto i : c)
        AddUI(i);
}
