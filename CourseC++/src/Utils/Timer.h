#pragma once

#include <iostream>
#include <functional>
#include "IExercise.h"

class Timer
{
public:
    //Timer() = delete;
    Timer(const Timer&) = delete;

    static Timer& Get()
    {
        static Timer s_Instance;
        return s_Instance;
    }

    void SetOnTick(const std::function<void(double dElapsedTime)>& OnTick);
    void Start(double dPeriod);
    void Stop();
    void Update(float deltaTime);

private:
    Timer(){}

    bool m_isActive = false;
    double m_dElapsedTime = 0;
    double m_dPeriod = 0;
    std::function<void(double dElapsedTime)> m_OnTick = {};

};

