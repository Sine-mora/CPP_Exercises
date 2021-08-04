#include "Timer.h"

void Timer::SetOnTick(const std::function<void(double ElapsedTime)>& OnTick)
{
    m_OnTick = OnTick;
     std::cout <<"Set ontick !\n";
}

void Timer::Start(double dPeriod)
{
    m_dPeriod = dPeriod;
    m_isActive = true;
    m_dElapsedTime = 0;
}

void Timer::Stop()
{
    m_isActive = false;
}

void Timer::Update(float deltaTime)
{
    if (m_isActive)
    {
        m_dElapsedTime += deltaTime;


        if (m_dElapsedTime >= m_dPeriod)
        {
            std::cout <<"In second if\n";
            if (m_OnTick)
            {
                std::cout <<"In third if\n";
                m_OnTick(m_dElapsedTime);
            }
            m_dElapsedTime = 0;
        }
    }
}

