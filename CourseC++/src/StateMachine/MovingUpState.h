#pragma once

#include "IState.h"
#include "EState.h"
#include "StateManager.h"


class MovingUpState : public IState
{
public:
    MovingUpState(StateManager* ptrOwner);
    MovingUpState() = default;
    ~MovingUpState() override = default;

    /* Override with behaviors for this state */
    void Update(float fDeltaTime) override;
    void OnEnter() override;
    void OnExit() override;
    EState GetStateName() const override;
};
