#include <cmath>
#include "Mesh.h"
#include "Settings.h"

constexpr float PI = 3.14159265f;

Mesh::Mesh(Settings const& settings)
: m_resolution(settings.GetMeshResolution())
{
}

void Mesh::GenerateCircle(float radius)
{
    _GenerateSector(radius, 2 * PI);
}

void Mesh::GenerateHalfCircle(float radius)
{
    _GenerateSector(radius, PI);
}

void Mesh::GenerateRectangle(float width, float height)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        for(int j = 0; j < m_resolution; j++)
        {
            m_vertices[m_resolution * i + j].x = (1.f*i / (m_resolution - 1) - 0.5f) * width;
            m_vertices[m_resolution * i + j].y = (1.f*j / (m_resolution - 1) - 0.5f) * height;
            m_vertices[m_resolution * i + j].z = 0.f;
        }
    }
}
void Mesh::GenerateSquare(float side)
{
    GenerateRectangle(side, side);
}

void Mesh::Debug() const
{
    for(Vertex const& vertex : m_vertices)
    {
        vertex.Debug();
    }
}

void Mesh::_GenerateSector(float radius, float angle)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        float r = (radius * i) / (m_resolution - 1);
        for(int j = 0; j < m_resolution; j++)
        {
            float theta = (angle * j) / (m_resolution - 1);
            m_vertices[m_resolution * i + j].x = r * std::cos(theta);
            m_vertices[m_resolution * i + j].y = r * std::sin(theta);
            m_vertices[m_resolution * i + j].z = 0.f;
        }
    }
}


void Vertex::Rotate(float angle, Axis axis)
{
    float c = std::cos(angle);
    float s = std::sin(angle);

    float ox = x;
    float oy = y;
    float oz = z;

    switch(axis)
    {
        case Axis::X:
            y = oy * c - oz * s;
            z = oy * s + oz * c;
            break;
        case Axis::Y:
            x = ox * c + oz * s;
            z = -ox * s + oz * c;
            break;
        case Axis::Z:
            x = ox * c - oy * s;
            y = ox * s + oy * c;
            break;
    }
}

void Mesh::Rotate(float angle, Axis axis)
{
    for(auto &v : m_vertices)
    {
        v.Rotate(angle, axis);
    }
}


void Mesh::GenerateTorus(float majorRadius, float minorRadius)
{
    if (majorRadius <= 0.f || minorRadius <= 0.f || m_resolution < 2)
    {
        m_vertices.clear();
        return;
    }

    m_vertices.resize(m_resolution * m_resolution);

    float zShift = majorRadius + minorRadius + 1.0f;

    for (int i = 0; i < m_resolution; ++i)
    {
        float phi = 2.0f * PI * i / m_resolution;
        float cosPhi = std::cos(phi);
        float sinPhi = std::sin(phi);

        for (int j = 0; j < m_resolution; ++j)
        {
            float theta = 2.0f * PI * j / m_resolution;
            float cosTheta = std::cos(theta);
            float sinTheta = std::sin(theta);

            float x = (majorRadius + minorRadius * cosTheta) * cosPhi;
            float y = minorRadius * sinTheta; 
            float z = (majorRadius + minorRadius * cosTheta) * sinPhi;

            m_vertices[m_resolution * i + j].x = x;
            m_vertices[m_resolution * i + j].y = y;
            m_vertices[m_resolution * i + j].z = z + zShift;
        }
    }
}