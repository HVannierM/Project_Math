#include "Screen.h"
#include <iostream>
#include <windows.h>

Screen::Screen(Settings settings) : ScreenSettings(settings) {

}

void Screen::ClearConsole()
{
    std::cout << "\x1B[2J";
}

void Screen::ShowCursor()
{
    std::cout << "\x1B[?25h";
}

void Screen::HideCursor()
{
    std::cout << "\x1B[?25l";
}

void Screen::SetCursorStartPos()
{
    std::cout << "\x1B[H";
}



void Screen::InitConsole() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;

    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void Screen::SetConsoleSize(int width, int height)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD bufferSize;
    bufferSize.X = width;
    bufferSize.Y = height;
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = width - 1;
    windowSize.Bottom = height - 1;
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

void Screen::Display() {
    for (int i = 0; i < ScreenSettings.GetHeight(); i++)
    {
        for (int j = 0; j < ScreenSettings.GetWidth(); j++)
        {
            std::cout << '.';
        }
        std::cout << std::endl;
    }
}