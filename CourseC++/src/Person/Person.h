#pragma once

#include "IExercise.h"
#include "pugixml.hpp"
#include <iostream>
#include <string>
#include <vector>

class Person : public IExercise
{
public:
    Person(const std::string& strName = "N/A",
           double dBalance = 4000,
           int nMobile = 12345,
           int nAccount = 0001);
    ~Person() override = default;
    void PrintName();
    void RunExercise() final;
    void ParseXML(const pugi::xml_node& user);

    const std::string& GetName() const;
    int GetMobileNumber() const;
    double GetBalance() const;
    int GetAccountNumber() const;

protected:
    void SetName(const std::string& strNewName);
    void SetMobileNumber(int nNewNumber);
    void SetBalance(double dBalance);
    void SetAccountNumber(int nAccountNumber);

private:
    std::string m_strName;
    double m_dBalance;
    int m_nMobileNumber;
    int m_nAccountNumber;
};
