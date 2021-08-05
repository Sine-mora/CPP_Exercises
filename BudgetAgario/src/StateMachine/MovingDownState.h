#pragma once

#include "IState.h"
#include "EState.h"
#include "StateManager.h"

class MovingDownState : public IState
{
public:
    MovingDownState(StateManager* ptrOwner);
    MovingDownState() = default;
    ~MovingDownState() override = default;

    /* Override with behaviors for this state */
    void Update(float fDeltaTime) override;
    void OnEnter() override;
    void OnExit() override;
    EState GetStateName() const override;
};
