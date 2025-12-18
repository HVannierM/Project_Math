#pragma once
#include "Mesh.h"
class Settings;

class Light
{
	Vertex m_lightVertex;

public:
	Light(Settings const& settings);
	float GetNormalizedLight();
};

