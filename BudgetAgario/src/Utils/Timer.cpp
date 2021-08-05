#include "Timer.h"

void SharedData::SetOnTick(const std::function<void(double ElapsedTime)>& OnTick)
{
    m_OnTick = OnTick;
    std::cout << "Set ontick !\n";
}

void SharedData::TimerStart(double dPeriod)
{
    m_dPeriod = dPeriod;
    m_isActive = true;
    m_dElapsedTime = 0;
}

void SharedData::TimerStop()
{
    m_isActive = false;
}

void SharedData::TimerUpdate(float deltaTime)
{
    if (m_isActive)
    {
        m_dElapsedTime += deltaTime;

        if (m_dElapsedTime >= m_dPeriod)
        {
            std::cout << "In second if\n";
            if (m_OnTick)
            {
                std::cout << "In third if\n";
                m_OnTick(m_dElapsedTime);
            }
            m_dElapsedTime = 0;
        }
    }
}

SDL_Rect& SharedData::GetRect()
{
    return m_textureRect;
}

SDL_Point& SharedData::GetProjectileVelocity()
{
    return m_ProjectileVelocity;
}

SDL_Point& SharedData::GetWindowDimensions()
{
    return m_WindowDimensions;
}
