#pragma once

#include "IState.h"
#include "EState.h"


class GameMenuState : public IState
{
public:
    GameMenuState(StateManager* ptrOwner);
    GameMenuState() = default;
    ~GameMenuState() override = default;

    /* Override with behaviors for this state */
    void Update(float fDeltaTime) override;
    void OnEnter() override;
    void OnExit() override;
    EState GetStateName() const override;
};
