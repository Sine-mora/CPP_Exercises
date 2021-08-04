#include "MovingDownState.h"


MovingDownState::MovingDownState(StateManager* ptrOwner): IState (ptrOwner)
{

}

void MovingDownState::Update(float fDeltaTime)
{
    (void)fDeltaTime;
}

void MovingDownState::OnEnter()
{

}

void MovingDownState::OnExit()
{

}

EState MovingDownState::GetStateName() const { return EState::eMovingDownState; }
