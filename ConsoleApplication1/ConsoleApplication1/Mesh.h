#pragma once
#include <iostream>
#include <vector>
struct Vertex {
	float x;
	float y;
	float z;
};

class Mesh
{

public:
	void Debug();
private:
	std::vector<Vertex> Vertexs;

};

