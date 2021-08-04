#pragma once

#include <string>

class Employees
{
public:
    Employees();
    ~Employees()=default;
private:
    std::string firstName="";
    std::string familyName="";
    bool isFemale =false;
    short iD =0;
    double uEN =0;

};
