#include "Functions.h"

void Functions::RunExercise()
{
    IsOdd(44) ? std::cout << 44 << " is odd.\n" : std::cout << 44 << " is even.\n";
    IsArmstrong(153) ? std::cout << 153 << " is Armstrong.\n" : std::cout << 153
                                                                          << " is not.\n";
}

bool Functions::IsOdd(uint32_t unNumber)
{
    return (unNumber % 2 != 0);
}

bool Functions::IsArmstrong(uint32_t unNumber)
{
    uint32_t unTemp = unNumber;
    uint32_t unSum = 0, unDigit = 0;

    while (unNumber > 0)
    {
        unDigit = unNumber % 10;
        unSum = unSum + (unDigit * unDigit * unDigit);
        unNumber = unNumber / 10;
    }

    return unTemp == unSum;
}
