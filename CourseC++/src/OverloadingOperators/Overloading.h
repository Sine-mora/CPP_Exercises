#pragma once

#include <iostream>

class Overloading
{
public:
    Overloading() = default;
    ~Overloading() = default;
    void GetWeight();
    
    //Precrement
    void operator++ ();
    
    //Postcrement
    void operator++ (int);
    
private:
    int weight;
};
