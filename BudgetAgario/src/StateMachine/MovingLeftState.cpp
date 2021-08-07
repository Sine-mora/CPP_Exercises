#include "MovingLeftState.h"

MovingLeftState::MovingLeftState(StateManager* ptrOwner): IState (ptrOwner)
{

}

void MovingLeftState::Update(float fDeltaTime)
{
    std::cout <<"\nLeft: "<< GetTextureRect().x << " x-y " << GetTextureRect().y << "\n";
    GetTextureRect().x -= static_cast<int>(static_cast<float>(GetVelocity().x) * fDeltaTime);
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
