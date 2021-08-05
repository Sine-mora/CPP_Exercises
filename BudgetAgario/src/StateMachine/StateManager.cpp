#include "StateManager.h"

#include <iostream>
#include <map>

StateManager::StateManager() : m_mapStates{}, m_ptrCurrentState{nullptr}
{
}

void StateManager::Update(float fDeltaTime)
{
    if (m_ptrCurrentState != nullptr)
    {
        m_ptrCurrentState->Update(fDeltaTime);
    }
    else
    {
        std::cout <<"\nNULLPTR\n";
    }
}
void StateManager::ChangeState(const EState eStateName)
{

    if (m_ptrCurrentState)
    {
        m_ptrCurrentState->OnExit();
    }

    //m_iterCurrentState = m_mapStates.find(eStateName);
    auto stateIt = m_mapStates.find(eStateName);
    if (stateIt != m_mapStates.end())
    {
        m_ptrCurrentState = stateIt->second.get();
        m_ptrCurrentState->OnEnter();
    }
    else
    {
        std::cout << "\nCould not find State.\n";
        m_ptrCurrentState = nullptr;
    }
}

void StateManager::RegisterState(IState* ptrState)
{
    if (ptrState)
    {
        m_mapStates.insert(std::make_pair(ptrState->GetStateName(), ptrState));
    }
}
