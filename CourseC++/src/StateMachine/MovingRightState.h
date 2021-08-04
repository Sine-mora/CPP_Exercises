#pragma once

#include "IState.h"
#include "EState.h"
#include "StateManager.h"


class MovingRightState : public IState
{
public:
    MovingRightState(StateManager* ptrOwner);
    MovingRightState() = default;
    ~MovingRightState() override = default;

    /* Override with behaviors for this state */
    void Update(float fDeltaTime) override;
    void OnEnter() override;
    void OnExit() override;
    EState GetStateName() const override;
};
