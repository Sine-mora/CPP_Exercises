#include "MovingUpState.h"

MovingUpState::MovingUpState(StateManager* ptrOwner): IState (ptrOwner)
{

}

void MovingUpState::Update(float fDeltaTime)
{
    GetTextureRect().y -=static_cast<int>(GetVelocity().y * fDeltaTime);
        std::cout<< "Vel.y " << GetVelocity().y<<"\n";
}

void MovingUpState::OnEnter()
{

}

void MovingUpState::OnExit()
{

}

EState MovingUpState::GetStateName() const { return EState::eMovingUpState; }
