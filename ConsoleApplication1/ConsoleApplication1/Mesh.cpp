#include "Mesh.h"

void Mesh::Debug() {
	std::cout << "========Vertcies========\n" << std::endl;
	for (int i = 0; i < Vertexs.size(); i++) {
		std::cout << i << "x: " << Vertexs[i].x << "y: " << Vertexs[i].y << "z: " << Vertexs[i].z << std::endl;
	}
}