#pragma once

class Settings
{
    public:
    Settings(int argc, char** argv);
    int GetScreenWidth() const { return m_screenWidth; }
    int GetScreenHeight() const { return m_screenHeight; }
    int GetMeshResolution() const { return m_meshResolution; }

    int GetScreenBackground() const { return m_screenBackground; }
    int GetScreenMeshProjection() const { return m_screenMeshProjection; }
    int GetScreenPosition() const { return m_screenPosition; }
    int GetMeshPosition() const { return m_meshPosition; }
    int GetFrameDuration() const { return m_frameDuration; }
    int GetMeshRotationXPerFrame() const { return m_meshRotationXPerFrame; }

    private:
    void _ParseArguments(int argc, char** argv);

    private:
    int m_screenWidth;
    int m_screenHeight;
    int m_meshResolution;
    char m_screenBackground;
    char m_screenMeshProjection;
    float m_screenPosition;
    int m_meshPosition;
    int m_frameDuration;
    int m_meshRotationXPerFrame;
};