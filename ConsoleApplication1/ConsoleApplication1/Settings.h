#pragma once
#include <iostream>
#include <string>
class Settings
{
	int m_height = 20;
	int m_width = 100;
	int m_meshResolution = 32;

public:
	Settings();
	Settings(int argc, char** argv);

	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }
	int GetMeshResolution() { return m_meshResolution; }

private:
	void ParseArguments(int argc, char** argv);
};

