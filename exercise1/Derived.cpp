#include "Derived.h"

Derived::Derived()
{
    std::cout<<"I am Derived().\n";
}

Derived::~Derived()
{
    std::cout<<"I am ~Derived().\n";
}

void Derived::F()
{
    std::cout << "I am Derived::F().\n";
}
