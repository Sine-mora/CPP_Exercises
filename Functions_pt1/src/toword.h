#ifndef TOWORD_H
#define TOWORD_H

#include <iostream>
#include <vector>

enum ENumbers
{
    eZero = 0,
    eOne = 1,
    eTwo = 2,
    eThree = 3,
    eFour = 4,
    eFive = 5,
    eSix = 6,
    eSeven = 7,
    eEight = 8,
    eNine = 9,
    eTen = 10,
    eEleven = 11,
    eTwelve = 12,
    eThirteen = 13,
    eFourteen = 14,
    eFifteen = 15,
    eSixteen = 16,
    eSeventeen = 17,
    eEighteen = 18,
    eNineteen = 19,
    eTwenty = 20,
    eThirty = 30,
    eFourty = 40,
    eFifty = 50,
    eSixty = 60,
    eSeventy = 70,
    eEighty = 80,
    eNinety = 90,
    eHundred = 100,
    eThousand = 1000
};

class ToWord
{
public:
    ToWord();
    ~ToWord() = default;
    void PrintNumToWords(int nNumber);

private:
    bool CheckForZero(int nNumber);
    void FillVector(int nNumber);
    void Calculate(std::vector<std::string>& vStringDigits);
    void PrintNumbers(const std::vector<std::string>& vStringDigits);
    void SingleDigit(std::size_t itr, uint32_t unDigit, std::string& strOutDigit);
    void DoubleDigits(std::size_t itr, uint32_t unDigit, std::string& strOutDigit);
    void TripleDigits(uint32_t unDigit, std::string& strOutDigit);
    void FourDigits(uint32_t unDigit, std::string& strOutDigit);

private:
    std::string isZero();
    std::vector<unsigned int> m_vNumber = {};
    std::vector<int> m_vNumberReverse = {};
    std::vector<std::string> m_vSingleDigit = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    std::vector<std::string> m_vTen = {"Ten",
                                       "Eleven",
                                       "Twelve",
                                       "Thirteen",
                                       "Fourteen",
                                       "Fifteen",
                                       "Sixteen",
                                       "Seventeen",
                                       "Eighteen",
                                       "Nineteen"};
    std::vector<std::string> m_vDoubleDigits = {
        "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    std::string m_strHundreds = "Hundred";
    std::string m_strThousand = "Thousand";
};

#endif // TOWORD_H
