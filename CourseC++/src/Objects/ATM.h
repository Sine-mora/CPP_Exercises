#pragma once

#include "pugixml.hpp"
#include "IExercise.h"
#include "Person/Person.h"
#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>

class ATM : public IExercise
{
public:
    ATM();
    ~ATM() override = default;
    void Initialize();
    void RunExercise() final;
    void ATMMenu();
    void CheckBalance();
    void CashWithDraw();
    void FillVectorOfUsers();
    void PrintUsers();
private:
    Person m_user;
    std::vector<Person> m_vUsers = {};
    std::function<int(int a, int b)> Test;
    std::function<bool(const Person& a, const Person& b)> m_Comparator;
};
