#include "MovingUpState.h"

MovingUpState::MovingUpState(StateManager* ptrOwner): IState (ptrOwner)
{

}

void MovingUpState::Update(float fDeltaTime)
{
    std::cout <<"\nUp: "<< GetTextureRect().x << " x-y " << GetTextureRect().y << "\n";
    GetTextureRect().y -= static_cast<int>(static_cast<float>(GetVelocity().y) * fDeltaTime);

    if (GetTextureRect().y <= 0)
    {
        std::cout <<"in IF UP REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEee";
        GetPtrOwner()->ChangeState(EState::eMovingDownState);
    }
}

void MovingUpState::OnEnter()
{
    std::cout <<"\nUpState;";
    //GetPtrOwner()->Update()
}

void MovingUpState::OnExit()
{
    std::cout << "\n Upstate Exit";
}

EState MovingUpState::GetStateName() const { return EState::eMovingUpState; }
