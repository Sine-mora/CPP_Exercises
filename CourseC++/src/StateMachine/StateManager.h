#pragma once

#include "EState.h"
#include "IState.h"
#include <iostream>
#include <map>
#include <memory>

class StateManager
{
public:
    using MapOfStates = std::map<EState, std::unique_ptr<IState>>;
    using MapOfStatesIter = std::map<EState, std::unique_ptr<IState>>::iterator;

    StateManager();
    ~StateManager() = default;

    //MapOfStatesIter GetCurrentState() const { return m_iterCurrentState; }

    void Update(float fDeltaTime);
    void RegisterState(IState* ptrState);
    void ChangeState(const EState eStateName);
    IState* GetCurrentState() const { return m_ptrCurrentState; }

private:

    MapOfStates m_mapStates;
    MapOfStatesIter m_iterCurrentState;
    IState* m_ptrCurrentState;
};
