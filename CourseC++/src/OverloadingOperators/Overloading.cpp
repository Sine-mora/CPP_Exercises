#include "Overloading.h"

// Precrement
void Overloading::operator++()
{
    ++weight;
}

// Postcrement
void Overloading::operator++(int)
{
    weight++;
}
