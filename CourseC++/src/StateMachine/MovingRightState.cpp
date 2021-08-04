#include "MovingRightState.h"

MovingRightState::MovingRightState(StateManager* ptrOwner): IState (ptrOwner)
{

}

void MovingRightState::Update(float fDeltaTime)
{
(void)fDeltaTime;
}

void MovingRightState::OnEnter()
{

}

void MovingRightState::OnExit()
{

}

EState MovingRightState::GetStateName() const { return EState::eMovingRightState; }
