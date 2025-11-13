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
	Mesh(int res);
	void Debug();
	void GenerateCircle(float radius);
	void GenerateHalfCircle(float radius);
	void GenerateRectangle(float width, float height);
	void GenerateSquare(float size);

private:
	std::vector<Vertex> Vertexs;

};

