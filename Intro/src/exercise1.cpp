#include "exercise1.h"

Exercise1::Exercise1()
{
    std::cout<<"Exercise 1 Constructor\n";
}

void Exercise1::PrintName()
{
    std::cout<<"Emanuil Iliev\n";
}

void Exercise1::PrintSqrt(double sqrtOf)
{
    std::cout<<"square root of "<<sqrtOf<<" is "<<sqrt(sqrtOf)<<"\n";
}

double Exercise1::GetSqrtVar()
{
    return sqrtOf;
}
