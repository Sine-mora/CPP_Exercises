#include "NumReverser.h"
#include "toword.h"
#include <iostream>
#include <string>
enum class EnumNumbers
{
    Zero,
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine
};

class Person
{
public:
    void PrintName() { std::cout << "\n Your name is: " << m_sName << "\n"; }

    void InsertName()
    {
        std::cout << "\nInsert your name: ";
        std::getline(std::cin, m_sName);
    }

    int GetMax(int nFirstNum, int nSecondNum)
    {
        if (nFirstNum > nSecondNum)
        {
            std::cout << "The first number is bigger: " << nFirstNum << "\n";
            return nFirstNum;
        }
        else if (nSecondNum > nFirstNum)
        {
            std::cout << "The second number is bigger: " << nSecondNum << "\n";
            return nSecondNum;
        }
        else
        {
            std::cout << "They are identical: " << nFirstNum << " " << nSecondNum << "\n";

            return nFirstNum;
        }
    }

    void InsertNumber()
    {
        int nFirstNum = 0, nSecondNum = 0;
        std::cout << "\nInsert 2 numbers to compare.";
        std::cout << "\nInsert first number: ";
        std::cin >> nFirstNum;
        std::cout << "\nInsert second number: ";
        std::cin >> nSecondNum;

        GetMax(nFirstNum, nSecondNum);
    }

    std::string ToWord(EnumNumbers number)
    {
        switch (number)
        {
        case EnumNumbers::Zero:
            return "Zero";

        case EnumNumbers::One:
            return "One";

        case EnumNumbers::Two:
            return "Two";

        case EnumNumbers::Three:
            return "Three";

        case EnumNumbers::Four:
            return "Four";

        case EnumNumbers::Five:
            return "Five";

        case EnumNumbers::Six:
            return "Six";

        case EnumNumbers::Seven:
            return "Seven";

        case EnumNumbers::Eight:
            return "Eight";

        case EnumNumbers::Nine:
            return "Nine";
        }
        return "DANONE";
    }

    void InsertOneNumber()
    {
        int nNumber = 0;
        std::cout << "Insert a number to get its last digit as a word.\n";
        std::cin >> nNumber;
        std::cout << ToWord(ToEnum(nNumber)) << "\n";
    }

    EnumNumbers ToEnum(int nNumber)
    {
        int result = nNumber % 10;
        return static_cast<EnumNumbers>(result);
    }

private:
    std::string m_sName = "";
};

int main()
{
    Person person;

    // person.InsertName();
    // person.PrintName();

    // person.InsertNumber();
    // person.InsertOneNumber();

    //   NumReverser reverse;
    // reverse.ReverseNumsV2(123);

    ToWord toWord;

    int nNum = 0;
    bool isRunning = true;
    while (isRunning)
    {
        std::cout << "\nWrite a number: \n";
        std::cin >> nNum;
        toWord.PrintNumToWords(nNum);
        if (nNum < 0)
        {
            isRunning = false;
        }
    }

    return 0;
}
