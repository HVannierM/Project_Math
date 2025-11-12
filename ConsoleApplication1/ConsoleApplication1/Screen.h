#pragma once
#include "Settings.h"

class Screen
{
public:
    Screen(Settings settings);
    void InitConsole();
    void SetConsoleSize(int width, int height);

    void ClearConsole();
    void ShowCursor();
    void HideCursor();
    void SetCursorStartPos();
    void Display();
private:
    Settings ScreenSettings;
};

