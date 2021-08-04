#include "GameMenuState.h"

GameMenuState::GameMenuState(StateManager* ptrOwner): IState (ptrOwner)
{
}

void GameMenuState::Update(float fDeltaTime)
{
    Timer::Get().Update(fDeltaTime);
}

void GameMenuState::OnEnter()
{
    std::cout << "\nGameMenuState-OnEnter: ";
    Timer::Get().Start(2);
    Timer::Get().SetOnTick([](double dElapsedTime) {
        std::cout << "Game Menu state : Elapsed time: " << dElapsedTime << "\n";
    });

}

void GameMenuState::OnExit()
{
    std::cout << "\nGameMenuState-OnExit: ";
}

EState GameMenuState::GetStateName() const
{
    return EState::eGameMenuState;
}
