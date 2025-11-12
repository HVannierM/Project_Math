#include <iostream>
#include "Settings.h"
#include "Screen.h"



int main(int argc, char**argv)
{
    Settings settings(argc,argv);

    Screen screen(settings);

    screen.InitConsole();
    screen.SetConsoleSize(settings.GetWidth(), settings.GetHeight());

    screen.ClearConsole();
    screen.SetCursorStartPos();    
    screen.HideCursor();

    screen.Display();

    screen.ShowCursor();

    return 0;
}

