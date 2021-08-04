#include "NumReverser.h"

NumReverser::NumReverser() = default;

void NumReverser::ReverseNums(int nNumber)
{

    int result = 0;
    // std::vector<int> vOriginalNum = {};
    std::vector<int> vReversedNum = {};

    while (nNumber > 0)
    {
        result = nNumber % 10;
        nNumber = nNumber / 10;

        vReversedNum.push_back(result);
        std::cout << "Number: " << nNumber << " Result: " << result << "\n";
    }

    std::cout << "Reversed Number is: \n";
    for (int itr = 0; itr < static_cast<int>(vReversedNum.size()); itr++)
    {
        std::cout << vReversedNum.at(itr);
        // std::cout << vReversedNum.at(itr) << " ";
    }
    std::cout << "\n";
}

void NumReverser::ReverseNumsV2(int nNumber)
{
    std::vector<int> vReversedNum = {};
    int result = 0;
    unsigned int itr = 0;
    double fullNum = 0;
    bool isRunning = true;

    if (isRunning)
    {       
        while (nNumber > 0)
        {
            result = nNumber % 10;
            nNumber = nNumber / 10;
            vReversedNum.push_back(result);
            std::cout << "Number: " << nNumber << " Result: " << result << "\n";
            std::cout << "Rev.Num: " << vReversedNum.at(itr) << "\n";
            itr++;
            fullNum = (fullNum + result) * 10;
        }
        std::cout<<"Full number: " << fullNum/10<<"\n";

        /*for (itr = vReversedNum.size() - 1; itr >= 0; itr--)
        {
            int reversedDigit = vReversedNum.at((vReversedNum.size() - 1) - itr);
            fullNum += (reversedDigit * std::pow(10, itr));
            std::cout << fullNum << "\n";
        }*/

    }
    else
    {
        isRunning = false;
    }
}
