#pragma once

#include <iostream>
#include <cmath>

class Exercise1
{
public:
    Exercise1();
    ~Exercise1()=default;
    void PrintName();
    void PrintSqrt(double sqrtOf);
    double GetSqrtVar();
private:
    double sqrtOf = 12345;
};
