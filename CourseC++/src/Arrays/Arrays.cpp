#include "Arrays.h"

void Arrays::RunExercise()
{
    constexpr int nRows = 4;
    constexpr int nColls = 4;
    int nPrimaryTotal = 0, nSecondaryTotal = 0, nLargest = 0;
    std::array<std::array<int32_t, nColls>, nRows> arrSum;
    int nTotal = 0;

    for (auto& i : arrSum)
    {
        for (auto& j : i)
        {
            std::cout << "Insert a number: ";
            std::cin >> j;
            nTotal += j;
        }
    }

    int nCurrRow = 0;
    for (const auto& i : arrSum)
    {
        int nCurrColl = 0;
        for (const auto& j : i)
        {
            std::cout << " " << j;
            if (nCurrRow == nCurrColl)
            {
                if (j % 2 == 0)
                {
                    nPrimaryTotal += j;
                }
            }

            if (nCurrRow + nCurrColl == arrSum.size() - 1)
            {
                if (j % 2 != 0)
                {
                    nSecondaryTotal += j;
                }
            }

            // Find Largest
            if (nLargest < j)
            {
                nLargest = j;
            }

            nCurrColl++;
        }
        std::cout << "\n";
        nCurrRow++;
    }
    std::cout << "\n Total amount : " << nTotal << "\n";
    std::cout << "Primary Total: " << nPrimaryTotal << "\n";
    std::cout << "Secondary Total: " << nSecondaryTotal << "\n";
    std::cout << "Largest number is: " << nLargest << "\n";
}
