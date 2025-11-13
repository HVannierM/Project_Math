#include "Mesh.h"

void Mesh::Debug() {
	std::cout << "========Vertcies========\n" << std::endl;
	for (int i = 0; i < Vertexs.size(); i++) {
		std::cout << i << "x: " << Vertexs[i].x << "y: " << Vertexs[i].y << "z: " << Vertexs[i].z << std::endl;
	}
}
void Mesh::GenerateCircle(float radius) {
	Vertexs.clear();
	if (radius <= 0.0f) return;

	const int segments = 32;
	const float PI = 3.1415f;
	Vertexs.reserve(segments);

	for (int i = 0; i < segments; ++i) {
		float angle = (2.0f * PI * i) / segments;
		Vertex v;
		v.x = std::cos(angle) * radius;
		v.y = std::sin(angle) * radius;
		v.z = 0.0f;
		Vertexs.push_back(v);
	}
}

void Mesh::GenerateHalfCircle(float radius) {
	Vertexs.clear();
	if (radius <= 0.0f) return;

	const int segments = 32; 
	const float PI = 3.1415f;
	Vertexs.reserve(segments + 1);

	for (int i = 0; i <= segments; ++i) { 
		float angle = (PI * i) / segments; 
		Vertex v;
		v.x = std::cos(angle) * radius;
		v.y = std::sin(angle) * radius;
		v.z = 0.0f;
		Vertexs.push_back(v);
	}
}

void Mesh::GenerateRectangle(float width, float height) {
	Vertexs.clear();
	if (width <= 0.0f || height <= 0.0f) return;

	float halfW = width * 0.5f;
	float halfH = height * 0.5f;

	Vertexs.push_back({ -halfW, -halfH, 0.0f });
	Vertexs.push_back({ halfW, -halfH, 0.0f });
	Vertexs.push_back({ halfW,  halfH, 0.0f });
	Vertexs.push_back({ -halfW,  halfH, 0.0f });
}

void Mesh::GenerateSquare(float size) {
	GenerateRectangle(size, size);
}