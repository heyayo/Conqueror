#include "classChoose.hpp"
#include "TextBox.hpp"
#include "Game.hpp"
#include "PictureBox.hpp"
#include "Archer.hpp"
#include "Warrior.hpp"
#include "Wizard.hpp"


TextBox* Title1;
PictureBox* c[4];
TextBox* Selectors[3];
std::string selectText = "ARCHER";
unsigned selection = 0;

void classChoose::SceneUpdate()
{
    switch (selection)
    {
        case ARCHER:
            selectText = "ARCHER";
            break;
        case WARRIOR:
            selectText = "WARRIOR";
            break;
        case WIZARD:
            selectText = "WIZARD";
            break;
        case HUGHJACKMAN:
            selectText = "HUGHJACKMAN";
            break;
    }
    Selectors[0]->SetTexts(&selectText, 1);
}

void classChoose::Collision()
{
    if (Selectors[1]->CalculateMouseCollision())
    {
        Selectors[1]->SetTextColor(BLUE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (selection > 0)
                --selection;
        }
    }
    else
        Selectors[1]->SetTextColor(BLACK);
    if (Selectors[2]->CalculateMouseCollision())
    {
        Selectors[2]->SetTextColor(BLUE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (selection < 3)
                ++selection;
        }
    }
    else
        Selectors[2]->SetTextColor(BLACK);
    if (Selectors[0]->CalculateMouseCollision())
    {
        Selectors[0]->SetTextColor(BLUE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            SetPlayersClass(static_cast<PLAYERCLASS>(selection));
            SaveState newSave;
            switch (GetPlayersClass())
            {
                case ARCHER:
                    newSave.health = 100;
                    newSave.damage = 1;
                    newSave.speed = 5;
                    break;
                case WARRIOR:
                    newSave.health = 150;
                    newSave.damage = 5;
                    newSave.speed = 2;
                    break;
                case WIZARD:
                    newSave.health = 80;
                    newSave.damage = 3;
                    newSave.speed = 5;
                    break;
                case HUGHJACKMAN:
                    newSave.health = 250;
                    newSave.damage = 100;
                    newSave.speed = 5;
                    break;
            }
            newSave.JournalCount = 0;
            newSave.currentLevel = LEVELONE;
            CreateSave(newSave);
            LoadSceneByEnum(LEVELONE);
        }
    }
    else
        Selectors[0]->SetTextColor(BLACK);
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

    Selectors[0] = new TextBox(&selectText,1);
    Selectors[0]->SetBoxColor(GOLD);
    Selectors[0]->SetTextColor(BLACK);
    Selectors[0]->SetAlignment(TextBox::CENTER);
    Selectors[0]->SetFontSize(30);
    Selectors[0]->SetSpacing(5);
    Selectors[0]->SetPadding(V2(80,0));
    Selectors[0]->SetPosition(GetScreenCenter());

    std::string leftarrow("<");
    V2 arrowOffset(120,0);
    Selectors[1] = new TextBox(&leftarrow, 1);
    Selectors[1]->SetBoxColor(GOLD);
    Selectors[1]->SetTextColor(BLACK);
    Selectors[1]->SetAlignment(TextBox::CENTER);
    Selectors[1]->SetFontSize(30);
    Selectors[1]->SetSpacing(5);
    Selectors[1]->SetPadding(V2(10,0));
    Selectors[1]->SetPosition(GetScreenCenter() - arrowOffset);

    std::string rightarrow(">");
    Selectors[2] = new TextBox(&rightarrow, 1);
    Selectors[2]->SetBoxColor(GOLD);
    Selectors[2]->SetTextColor(BLACK);
    Selectors[2]->SetAlignment(TextBox::CENTER);
    Selectors[2]->SetFontSize(30);
    Selectors[2]->SetSpacing(5);
    Selectors[2]->SetPadding(V2(10,0));
    Selectors[2]->SetPosition(GetScreenCenter() + arrowOffset);

    for (auto e : Selectors)
        AddUI(e);
    AddUI(Title1);
    for (auto i : c)
        AddUI(i);
}
