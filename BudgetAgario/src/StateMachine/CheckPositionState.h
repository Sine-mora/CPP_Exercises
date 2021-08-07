#pragma once

#include "IState.h"
#include "EState.h"
#include "StateManager.h"

class CheckPositionStateForX : public IState
{
public:
    CheckPositionStateForX(StateManager* ptrOwner);
    CheckPositionStateForX() =default;
    ~CheckPositionStateForX() override = default;

    void OnEnter() override;
    void Update(float fDeltaTime) override;
    void OnExit() override;
    EState GetStateName() const override;
};


class CheckPositionStateForY : public IState
{
public:
    CheckPositionStateForY(StateManager* ptrOwner);
    CheckPositionStateForY() =default;
    ~CheckPositionStateForY() override = default;

    void OnEnter() override;
    void Update(float fDeltaTime) override;
    void OnExit() override;
    EState GetStateName() const override;
};

