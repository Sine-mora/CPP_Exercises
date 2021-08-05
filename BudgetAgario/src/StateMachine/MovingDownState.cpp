#include "MovingDownState.h"

MovingDownState::MovingDownState(StateManager* ptrOwner): IState (ptrOwner)
{

}

void MovingDownState::Update(float fDeltaTime)
{
    GetTextureRect().y += static_cast<int>(GetVelocity().y * fDeltaTime);

    if(GetTextureRect().y >= (GetWindowDimensions().y - GetTextureRect().h) &&
        GetTextureRect().y )
    {
        GetPtrOwner()->ChangeState(EState::eMovingUpState);
    }
}
void MovingDownState::OnEnter()
{
    std::cout <<"\n Down Enter";
}

void MovingDownState::OnExit()
{
    std::cout <<"\n Down Exit";
}

EState MovingDownState::GetStateName() const { return EState::eMovingDownState; }
