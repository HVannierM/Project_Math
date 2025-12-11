#include <iostream>
#include <windows.h>
#include "Settings.h"
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

void ClearConsole()
{
    std::cout << "\x1b[2J"; // Remove all characters in console
    std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
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

int main(int argc, char** argv)
{
    InitConsole();
    ClearConsole();
    SetCursorVisible(false);

    Settings settings(argc, argv);
    Screen screen(settings);

    Mesh mesh(settings);
    mesh.GenerateTorus(4.0f,0.9f);

    while (true)
    {
        std::cout << "\x1b[H";
        mesh.Rotate(settings.GetMeshRotationXPerFrame(), Axis::Y);
        mesh.Rotate(settings.GetMeshRotationXPerFrame(), Axis::X);
        //mesh.Rotate(0.2, Axis::Z);

        screen.Display(mesh);

        Sleep(settings.GetFrameDuration()/1000);
    }

    return 0;
}