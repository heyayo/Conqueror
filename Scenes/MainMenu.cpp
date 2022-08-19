#include "MainMenu.hpp"
#include "TextBox.hpp"
#include "Game.hpp"

TextBox* Title;
TextBox* PButton;

MainMenu::MainMenu()
{
    Title = new TextBox("CONQUERORS DUNGEON");
    Title->SetTextColor(BLACK);
    Title->SetBoxColor(GOLD);
    Title->SetAlignment(TextBox::CENTER);
    Title->SetFontSize(120);
    Title->SetPadding(V2(100,100));
    V2 offset(0,300);
    Title->SetPosition(GetScreenCenter() + offset);
    AddUI(Title);

    PButton = new TextBox("START");
    PButton->SetTextColor(BLACK);
    PButton->SetBoxColor(GOLD);
    PButton->SetFontSize(40);
    PButton->SetPadding(V2(60,60));
    PButton->SetAlignment(TextBox::CENTER);
    PButton->SetPosition(GetScreenCenter());
    AddUI(PButton);
}

void MainMenu::SceneUpdate()
{
    SceneDraw();
    Collision();
}

void MainMenu::Collision()
{
    if (PButton->CalculateMouseCollision())
    {
        PButton->SetTextColor(BLUE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            LoadSceneByEnum(TESTSCENE);
        }
    }
    else
        PButton->SetTextColor(BLACK);
}
