#include "MovingRightState.h"

MovingRightState::MovingRightState(StateManager* ptrOwner): IState (ptrOwner)
{

}

void MovingRightState::Update(float fDeltaTime)
{
    GetTextureRect().x += static_cast<int>(GetVelocity().x * fDeltaTime);
    std::cout<< "Vel.x " << GetVelocity().x<<"\n";
}

void MovingRightState::OnEnter()
{
    std::cout << "\n On Enter - Right State";
}

void MovingRightState::OnExit()
{
    std::cout<<"\nOn Exit - Right State";
}

EState MovingRightState::GetStateName() const { return EState::eMovingRightState; }
