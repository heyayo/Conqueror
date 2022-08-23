#include "classChoose.hpp"
#include "TextBox.hpp"
#include "Game.hpp"
#include "PictureBox.hpp"

TextBox* Title1;
TextBox* PButton1;
PictureBox* c1;

void classChoose::SceneUpdate()
{
}

void classChoose::Collision()
{
    if (PButton1->CalculateMouseCollision())
    {
        PButton1->SetTextColor(BLUE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            LoadSceneByEnum(LEVELONE);
        }
    }
    else
        PButton1->SetTextColor(BLACK);
}

void classChoose::LoadScene()
{
    SetBG(GREEN);
    std::string mT("CHOOSE YOUR CLASS");
    Title1 = new TextBox(&mT, 1);
    Title1->SetTextColor(BLACK);
    Title1->SetBoxColor(GOLD);
    Title1->SetAlignment(TextBox::CENTER);
    Title1->SetFontSize(120);
    Title1->SetPadding(V2(100, 100));
    V2 offset(0, 300);
    Title1->SetPosition(GetScreenCenter() + offset);

    std::string mP("START");
    PButton1 = new TextBox(&mP, 1);
    PButton1->SetTextColor(BLACK);
    PButton1->SetBoxColor(GOLD);
    PButton1->SetFontSize(40);
    PButton1->SetPadding(V2(60, 60));
    PButton1->SetAlignment(TextBox::CENTER);
    PButton1->SetPosition(GetScreenCenter());

    c1 = new PictureBox;

    AddUI(Title1);
    AddUI(PButton1);
}
