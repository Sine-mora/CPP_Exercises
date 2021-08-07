#pragma once

#include "IExercise.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <functional>
#include <iostream>

class SharedData
{
public:
    // Timer() = delete;
    SharedData(const SharedData&) = delete;
    SharedData& operator=(const SharedData&) = delete;

    static SharedData& Get()
    {
        static SharedData s_Instance;
        return s_Instance;
    }

    // Timer
    void SetOnTick(const std::function<void(double dElapsedTime)>& OnTick);
    void SetMoveDirection(const std::function<void(float fDeltaTime)>& MoveDirection);
    const std::function<void(float)>& GetMoveDirection();
    void TimerStart(double dPeriod);
    void TimerStop();
    void TimerUpdate(float fdeltaTime);

    // SDL_Rectangle
    void RectUpdate(float fdeltaTime);
    SDL_Rect& GetRect();
    SDL_Point& GetProjectileVelocity();
    SDL_Point& GetWindowDimensions();

private:
    // Instantiate Timer class

    SharedData() = default;

    // Rectangle & Velocity
    SDL_Rect m_textureRect;
    SDL_Point m_ProjectileVelocity = {70, 340};

    // float m_fProjectileVelX = 240.5f, m_fProjectileVelY = 100.3f;

    bool m_isActive = false;
    double m_dElapsedTime = 0;
    double m_dPeriod = 0;
    std::function<void(double dElapsedTime)> m_OnTick = {};
    std::function<void(float fDeltaTime)> m_MoveInDirection = {};

    //Window's dimensions
    SDL_Point m_WindowDimensions = {600,800};
};
