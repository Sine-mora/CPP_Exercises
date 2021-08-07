#include "CheckPositionState.h"

CheckPositionStateForX::CheckPositionStateForX(StateManager *ptrOwner) : IState (ptrOwner)
{

}

void CheckPositionStateForX::OnEnter()
{
    std::cout<<"\nCheck Pos State: X ";
}

void CheckPositionStateForX::Update(float fDeltaTime)
{
    std::cout <<"'\nPosX update ";

    int nBorderX = (GetWindowDimensions().x - GetTextureRect().w);

    if (GetTextureRect().x >= nBorderX)
    {
        GetPtrOwner()->ChangeState(EState::eMovingLeftState);
        SharedData::Get().SetMoveDirection([&](float fDeltaTime){
            std::cout <<"\nMove Left ";
            GetTextureRect().x -= static_cast<int>(static_cast<float>(GetVelocity().x)*fDeltaTime);
        });
    }
    else if(GetTextureRect().x <= 0 )
    {
        GetPtrOwner()->ChangeState(EState::eMovingRightState);
        SharedData::Get().SetMoveDirection([&](float fDeltaTime){
            std::cout <<"\nMove Right ";
            GetTextureRect().x += static_cast<int>(static_cast<float>(GetVelocity().x)*fDeltaTime);
        });
    }
    else
    {
        
    }
    std::cout <<"\nRight X: "<< GetTextureRect().x << " Y: " << GetTextureRect().y << "\n";

}

void CheckPositionStateForX::OnExit()
{
    std::cout << "\nPos exit X";
}

EState CheckPositionStateForX::GetStateName() const
{
    return EState::eCheckPositionState;
}


CheckPositionStateForY::CheckPositionStateForY(StateManager* ptrOwner) : IState (ptrOwner)
{

}

void CheckPositionStateForY::OnEnter()
{
    std::cout<<"\nCheck Pos State: Y";
}

void CheckPositionStateForY::Update(float fDeltaTime)
{
    SharedData::Get().GetMoveDirection()(fDeltaTime);
}

void CheckPositionStateForY::OnExit()
{
    std::cout << "\nPos exit Y";

    int nBorderY = (GetWindowDimensions().y - GetTextureRect().h);

    if (GetTextureRect().y >= nBorderY)
    {
        GetPtrOwner()->ChangeState(EState::eMovingUpState);
        SharedData::Get().SetMoveDirection([&](float fDeltaTime){
            std::cout <<"\nMove Up ";
            GetTextureRect().y -= static_cast<int>(static_cast<float>(GetVelocity().y)*fDeltaTime);
        });
    }
    else if(GetTextureRect().y <= 0 )
    {
        GetPtrOwner()->ChangeState(EState::eMovingDownState);
        SharedData::Get().SetMoveDirection([&](float fDeltaTime){
            std::cout <<"\nMove Down ";
            GetTextureRect().y += static_cast<int>(static_cast<float>(GetVelocity().y)*fDeltaTime);
        });
    }


}

EState CheckPositionStateForY::GetStateName() const
{
    return EState::eCheckPositionState;
}


