#include <iostream>
#include <windows.h>
#include "Settings.h"
#include <signal.h> // To intercept kill ctrl+c
#include "Screen.h"
#include "Mesh.h"
constexpr float PI = 3.14159265f;

void InitConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void SetCursorToHomePosition()
{
    std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
}
void ClearConsole()
{
    std::cout << "\x1b[2J"; // Remove all characters in console
    SetCursorToHomePosition();
}

void SetCursorVisible(bool visible)
{
    if(visible)
    {
        std::cout << "\x1b[?25h"; // Make cursor visible
    }
    else
    {
        std::cout << "\x1b[?25l"; // Make cursor invisible
    }
}

void OnKill(int signum)
{
    ClearConsole();
    SetCursorVisible(true);
    exit(signum);
}

int main(int argc, char** argv)
{
    signal(SIGINT, OnKill);
    InitConsole();
    ClearConsole();
    SetCursorVisible(false);

    Settings settings(argc, argv);
    Screen screen(settings);

    Mesh mesh(settings);
    mesh.GenerateTorus(4.0f,0.9f);

    while (true)
    {
        SetCursorToHomePosition();
        mesh.Rotate(settings.GetMeshRotationXPerFrame(), Axis::Y);
        mesh.Rotate(settings.GetMeshRotationXPerFrame(), Axis::X);
        //mesh.Rotate(0.2, Axis::Z);

        screen.Display(mesh);

        Sleep(settings.GetFrameDuration()/1000);
    }

    return 0;
}