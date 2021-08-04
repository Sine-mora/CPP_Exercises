#include "MovingLeftState.h"

MovingLeftState::MovingLeftState(StateManager* ptrOwner): IState (ptrOwner)
{

}

void MovingLeftState::Update(float fDeltaTime)
{
(void)fDeltaTime;
}

void MovingLeftState::OnEnter()
{

}

void MovingLeftState::OnExit()
{

}

EState MovingLeftState::GetStateName() const { return EState::eMovingLeftState; }
