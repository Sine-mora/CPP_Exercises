#include "Exception.h"

void Exception::RunExercise()
{
    int nNum1 = 0, nNum2 = 0, nTotal = 0;

    std::cout << "\nEnter 2 numbers: ";
    std::cin >> nNum1 >> nNum2;
    try
    {
        if (nNum2 == 0)
        {
            std::cout <<"\nThrow nNum2:\n";
            throw nNum2;
        }
        else if (nNum1 == -1)
        {
            std::cout << "\nThrow nNum1:\n";
            throw nNum1;
        }
        else
        {
            nTotal = nNum1/nNum2;
            std::cout <<"\nTotal: "<<nTotal <<"\n";
        }
    }
    catch (int x)
    {
        std::cout << " Exception - Division by " << x;
    }
}
