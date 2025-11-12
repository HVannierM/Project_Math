#pragma once
#include <iostream>
#include <string>
class Settings
{
	int m_height = 20;
	int m_width = 100;

public:
	Settings();
	Settings(int argc, char** argv);

	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }
private:
	void ParseArguments(int argc, char** argv);
};

