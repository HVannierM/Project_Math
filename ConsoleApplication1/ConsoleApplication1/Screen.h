#pragma once
#include <vector>
class Mesh;
class Settings;

class Screen
{
    public:
    Screen(Settings const& settings);
    void Display() const;
    void Display(Mesh const& mesh); 

    private:
    int m_width;
    int m_height;
    char m_background;
    char m_screenMeshProjection;
    float m_screenPosition;
    int m_meshPosition;
    std::vector<char> m_pixels;
};