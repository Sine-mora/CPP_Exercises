#include "Base.h"

Base::Base()
{
    std::cout << "I am Base().\n";
}

Base::~Base()
{
    std::cout << "I am ~Base().\n";
}

void Base::F()
{
    std::cout << "I am Base::F().\n";
}
