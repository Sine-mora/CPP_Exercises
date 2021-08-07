#include "GameMenuState.h"

GameMenuState::GameMenuState(StateManager* ptrOwner): IState (ptrOwner)
{
}

void GameMenuState::Update(float fDeltaTime)
{
    SharedData::Get().TimerUpdate(fDeltaTime);
    std::cout << " Test delta time: "<<fDeltaTime;
}

void GameMenuState::OnEnter()
{
    std::cout << "\nGameMenuState - OnEnter: ";
    SharedData::Get().TimerStart(2);
//    SharedData::Get().SetOnTick([](double dElapsedTime) {
//        std::cout << "Game Menu state : Elapsed time: " << dElapsedTime << "\n";
//    });

}

void GameMenuState::OnExit()
{
    std::cout << "\nGameMenuState - OnExit: ";
}

EState GameMenuState::GetStateName() const
{
    return EState::eGameMenuState;
}
