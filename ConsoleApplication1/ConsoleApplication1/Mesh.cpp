#include <cmath>
#include "Mesh.h"
#include "Settings.h"

constexpr float PI = 3.14159265f;

Mesh::Mesh(Settings const& settings)
    : m_resolution(settings.GetMeshResolution())
    , m_screenwidth(settings.GetScreenWidth())
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

    Vertex previous = *this;
    float c = std::cos(angle);
    float s = std::sin(angle);


    switch(axis)
    {
        case Axis::X:
            y = previous.y * c - previous.z * s;
            z = previous.y * s + previous.z * c;
            break;
        case Axis::Y:
            x = previous.x * c + previous.z * s;
            z = - previous.x * s + previous.z * c;
            break;
        case Axis::Z:
            x = previous.x * c - (previous.y * s);
            y = previous.x * s + previous.y * c;
            break;
    }
}

void Mesh::Rotate(float angle, Axis axis)
{
    for(Vertex &v : m_vertices)
    {
        v.Rotate(angle, axis);
    }
}


void Mesh::GenerateTorus(float majorRadius, float minorRadius)
{
    m_vertices.clear();

    constexpr float twopi = 2 * PI;
    for (int i = 0; i < m_resolution; ++i)
    {
        float theta = (static_cast<float>(i) / m_resolution) * twopi;
        float cosTheta = cosf(theta);
        float sinTheta = sinf(theta);

        float circleOffset = majorRadius + minorRadius * cosTheta;

        for (int j = 0; j < m_resolution; ++j)
        {
            float phi = (static_cast<float>(j) / m_resolution) * 2 * twopi;
            float cosPhi = cosf(phi);
            float sinPhi = sinf(phi);

            Vertex v;
            v.x = circleOffset * cosPhi;
            v.y = minorRadius * sinTheta;
            v.z = circleOffset * sinPhi;

            m_vertices.push_back(v);
        }
    }
}
