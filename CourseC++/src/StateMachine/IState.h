#pragma once

#include "EState.h"
#include "Utils/Timer.h"

class StateManager;

class IState
{
public:
    IState(StateManager* ptrOwner) : m_ptrOwner(ptrOwner)
    {}
    IState() = default;
    virtual ~IState() = default;

    virtual void Update(float fDeltaTime) = 0;
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual EState GetStateName() const = 0;

private:
    StateManager* m_ptrOwner;

};
