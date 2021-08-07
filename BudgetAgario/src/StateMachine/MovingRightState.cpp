#include "MovingRightState.h"

MovingRightState::MovingRightState(StateManager* ptrOwner) : IState(ptrOwner)
{
}

void MovingRightState::Update(float fDeltaTime)
{
    std::cout << "\nRight X: " << GetTextureRect().x << " Y: " << GetTextureRect().y
              << "\n";

    int nBorderX = (GetWindowDimensions().x - GetTextureRect().w);

    GetTextureRect().x += static_cast<int>(static_cast<float>(GetVelocity().x) * fDeltaTime);

    std::cout << "\nRight X: " << GetTextureRect().x << " Y: " << GetTextureRect().y
              << "\n";

    if (GetTextureRect().x <= 0 && (GetStateName()!=EState::eMovingLeftState) )
//        GetPtrOwner()->ChangeState(EState::eMovingRightState);

    if (GetTextureRect().x >= nBorderX )
    {
        std::cout << " in IF RS: " << GetTextureRect().x
                  << "Point: " << nBorderX ;
        GetPtrOwner()->ChangeState(EState::eMovingLeftState);
    }
}

void MovingRightState::OnEnter()
{
    // TODO: Set Velocity here
    std::cout << "\nRight State";
}

void MovingRightState::OnExit()
{
    std::cout << "\nExit Right";
}

EState MovingRightState::GetStateName() const
{
    return EState::eMovingRightState;
}
