#include <iostream>
#include <windows.h>

void InitConsole() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;

    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

int main()
{
    InitConsole();
    std::cout << "Hello Wrold";
    std::cout << "\x1b[2J" << std::endl;
    std::cout << "\x1b[H" << std::endl;
    std::cout << "\x1b[?25l	" << std::endl;
    return 0;
}

