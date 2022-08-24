#include "MainMenu.hpp"
#include "TextBox.hpp"
#include "Game.hpp"

TextBox* Title;
TextBox* PButton;

void MainMenu::SceneUpdate()
{
}

void MainMenu::Collision()
{
    if (PButton->CalculateMouseCollision())
    {
        PButton->SetTextColor(BLUE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            LoadSceneByEnum(CLASSCHOOSE);
        }
    }
    else
        PButton->SetTextColor(BLACK);
}

void MainMenu::LoadScene()
{
    SetBG("SceneBG/mainmenu.png", V2(1920, 1080));

    std::string mT("CONQUERORS DUNGEON");
    Title = new TextBox(&mT, 1);
    Title->SetTextColor(BLACK);
    Title->SetBoxColor(GOLD);
    Title->SetAlignment(TextBox::CENTER);
    Title->SetFontSize(120);
    Title->SetPadding(V2(100,100));
    V2 offset(0,300);
    Title->SetPosition(GetScreenCenter() + offset);

    std::string mP("START");
    PButton = new TextBox(&mP, 1);
    PButton->SetTextColor(BLACK);
    PButton->SetBoxColor(GOLD);
    PButton->SetFontSize(40);
    PButton->SetPadding(V2(60,60));
    PButton->SetAlignment(TextBox::CENTER);
    PButton->SetPosition(GetScreenCenter());
    AddUI(Title);
    AddUI(PButton);
}
