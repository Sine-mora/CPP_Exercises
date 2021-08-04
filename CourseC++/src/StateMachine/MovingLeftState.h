#pragma once

#include "IState.h"
#include "EState.h"
#include "StateManager.h"


class MovingLeftState : public IState
{
public:
    MovingLeftState(StateManager* ptrOwner);
    MovingLeftState() = default;
    ~MovingLeftState() override = default;

    /* Override with behaviors for this state */
    void Update(float fDeltaTime) override;
    void OnEnter() override;
    void OnExit() override;
    EState GetStateName() const override;
};
