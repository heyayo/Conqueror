#include "WinStage.hpp"
#include "TextBox.hpp"
#include "Game.hpp"

TextBox* wAccouncer;
TextBox* jCounter;
TextBox* ender;
TextBox* continueKey;

void WinStage::LoadScene()
{
    SetBG(WHITE);
    V2 offset(0,100);
    std::string winMsg("You've Defeated The Dragon");
    wAccouncer = new TextBox(&winMsg,1);
    wAccouncer->SetFontSize(100);
    wAccouncer->SetTextColor(GOLD);
    wAccouncer->SetBoxColor(WHITE);
    wAccouncer->SetPadding(V2(50,50));
    wAccouncer->SetSpacing(2);
    wAccouncer->SetPosition(GetScreenCenter() - offset - offset - offset);
    wAccouncer->SetAlignment(TextBox::CENTER);

    SaveState pSave = LoadSave();
    std::string jCount[3];
    jCount[0] = "You Have Collected";
    jCount[1] = std::to_string(pSave.JournalCount);
    jCount[2] = "Journals";
    jCounter = new TextBox(jCount,3);
    jCounter->SetFontSize(100);
    jCounter->SetTextColor(GOLD);
    jCounter->SetBoxColor(WHITE);
    jCounter->SetPadding(V2(50,50));
    jCounter->SetSpacing(2);
    jCounter->SetPosition(GetScreenCenter());
    jCounter->SetAlignment(TextBox::CENTER);

    std::string fate;
    if (pSave.JournalCount >= 5)
        fate = "You've Conquered The Dungeon";
    else
        fate = "But the Dungeon has Conquered You";
    ender = new TextBox(&fate,1);
    ender->SetFontSize(100);
    ender->SetTextColor(GOLD);
    ender->SetBoxColor(WHITE);
    ender->SetPadding(V2(50,50));
    ender->SetSpacing(2);
    ender->SetPosition(GetScreenCenter() - offset - offset);
    ender->SetAlignment(TextBox::CENTER);

    std::string cont("CLICK ANYWHERE TO CONTINUE");
    continueKey = new TextBox(&cont,1);
    continueKey->SetFontSize(25);
    continueKey->SetTextColor(GOLD);
    continueKey->SetBoxColor(WHITE);
    continueKey->SetPadding(V2(50,50));
    continueKey->SetSpacing(2);
    continueKey->SetPosition(GetScreenCenter() - offset - offset - offset - offset);
    continueKey->SetAlignment(TextBox::CENTER);

    AddUI(wAccouncer);
    AddUI(jCounter);
    AddUI(ender);
    AddUI(continueKey);
}

void WinStage::SceneUpdate()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        LoadSceneByEnum(MAINMENU);
}

void WinStage::Collision()
{

}
