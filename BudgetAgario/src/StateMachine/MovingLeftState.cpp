#include "MovingLeftState.h"

MovingLeftState::MovingLeftState(StateManager* ptrOwner): IState (ptrOwner)
{

}

void MovingLeftState::Update(float fDeltaTime)
{
    GetTextureRect().x -= static_cast<int>(GetVelocity().x * fDeltaTime);
    std::cout<< "Vel.y " << GetVelocity().y<<"\n";
}

void MovingLeftState::OnEnter()
{
    std::cout <<"\n Enter Left ";
}

void MovingLeftState::OnExit()
{
    std::cout << "\nExit Left";
}

EState MovingLeftState::GetStateName() const { return EState::eMovingLeftState; }
