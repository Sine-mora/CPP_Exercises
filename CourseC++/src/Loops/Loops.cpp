#include "Loops.h"
#include <iostream>

void Loops::FindSum()
{
    // Find sum of first 10 natural numbers
    int nSum = 0;
    /*
    for(int i = 1; i <= 10; i++)
    {
        nSum += i;
    }
    */

    int i = 1;

    do
    {
        nSum += i;
        i++;
    }while (i <= 10);

    std::cout << "The sum is: " << nSum << "\n";
}

void Loops::RunExercise()
{
    FindSum();
}
