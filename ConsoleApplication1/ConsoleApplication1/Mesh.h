#pragma once
#include <cstdio>
#include <vector>
#include <iostream>

class Settings;

enum class Axis { X, Y, Z };

struct Vertex
{
    void Debug() const { std::printf("[x=%5.2f, y=%5.2f, z=%5.2f]\n", x, y, z); }
    void Rotate(float angle, Axis axis);
    float x;
    float y;
    float z;
};

class Mesh
{
    public:
    Mesh(Settings const& settings);
    void Debug() const;
    void GenerateCircle(float radius);
    void GenerateHalfCircle(float radius);
    void GenerateRectangle(float width, float height);
    void GenerateSquare(float side);

    void Rotate(float angle, Axis axis);

    std::vector<Vertex> GetVertices() const { return m_vertices; }

    void GenerateTorus(float majorRadius, float minorRadius);

    private:
    void _GenerateSector(float radius, float angle);

    std::vector<Vertex> m_vertices;
    int m_resolution;
};