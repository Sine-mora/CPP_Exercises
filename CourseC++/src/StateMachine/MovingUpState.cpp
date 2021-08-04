#include "MovingUpState.h"

MovingUpState::MovingUpState(StateManager* ptrOwner): IState (ptrOwner)
{

}

void MovingUpState::Update(float fDeltaTime)
{
(void)fDeltaTime;
}

void MovingUpState::OnEnter()
{

}

void MovingUpState::OnExit()
{

}

EState MovingUpState::GetStateName() const { return EState::eMovingUpState; }
