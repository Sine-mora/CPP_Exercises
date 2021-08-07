#include "MovingDownState.h"
#include "StateManager.h"

MovingDownState::MovingDownState(StateManager* ptrOwner) : IState(ptrOwner)
{
}

void MovingDownState::Update(float fDeltaTime)
{
    std::cout << "\nDown: " << GetTextureRect().x << " x-y " << GetTextureRect().y
              << "\n";
    GetTextureRect().y +=
        static_cast<int>(static_cast<float>(GetVelocity().y) * fDeltaTime);

    std::cout << "\n1 Down: " << GetTextureRect().x << " x-y " << GetTextureRect().y
              << "\n";

    if (GetTextureRect().y >= (GetWindowDimensions().y - GetTextureRect().h))
    {
        std::cout << "\nIF Down: " << GetTextureRect().x << " x-y " << GetTextureRect().y
                  << "Dimensions: " << (GetWindowDimensions().y - GetTextureRect().h);

        GetPtrOwner()->ChangeState(EState::eMovingUpState);
    }
}
void MovingDownState::OnEnter()
{
    std::cout << "\n Down Enter";


}

void MovingDownState::OnExit()
{
    std::cout << "\n Down Exit";
}

EState MovingDownState::GetStateName() const
{
    return EState::eMovingDownState;
}
