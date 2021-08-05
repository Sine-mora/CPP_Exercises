#pragma once

#include "EState.h"
#include "Utils/Timer.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class StateManager;

class IState
{
public:
    IState(StateManager* ptrOwner = nullptr) : m_ptrOwner(ptrOwner)
    {}
    virtual ~IState() = default;

    virtual void Update(float fDeltaTime) = 0;
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual EState GetStateName() const = 0;

    SDL_Rect& GetTextureRect()
    {
        return SharedData::Get().GetRect();
    }

    SDL_Point& GetVelocity()
    {
        return SharedData::Get().GetProjectileVelocity();
    }

    SDL_Point& GetWindowDimensions()
    {
        return SharedData::Get().GetWindowDimensions();
    }

    StateManager* GetPtrOwner()
    {
        return m_ptrOwner;
    }

private:
    StateManager* m_ptrOwner;


};
