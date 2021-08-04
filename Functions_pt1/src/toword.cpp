#include "toword.h"
#include <algorithm>

ToWord::ToWord() = default;

void ToWord::PrintNumToWords(int nNumber)
{
    if (CheckForZero(nNumber))
    {
        return;
    }

    // FillVector
    FillVector(nNumber);

    // Calculate
    std::vector<std::string> vStringDigits = {};
    Calculate(vStringDigits);

    // Print Number
    PrintNumbers(vStringDigits);
}

// Functions
std::string ToWord::isZero()
{
    return m_vSingleDigit.at(0);
}

bool ToWord::CheckForZero(int nNumber)
{
    if (nNumber == 0)
    {
        std::cout << nNumber << " -> " << m_vSingleDigit.at(0) << "\n";
        return true;
    }
    else
    {
        return false;
    }
}

void ToWord::FillVector(int nNumber)
{
    std::cout << nNumber << " -> ";
    int result = 0;
    m_vNumber.clear();
    while (nNumber > 0)
    {
        result = nNumber % 10;
        nNumber = nNumber / 10;
        m_vNumber.push_back(static_cast<unsigned int>(result));
    }
    std::reverse(m_vNumber.begin(), m_vNumber.end());
}

void ToWord::Calculate(std::vector<std::string>& vStringDigits)
{
    for (std::size_t itr = 0; itr < m_vNumber.size(); itr++)
    {
        auto unDigit = static_cast<uint32_t>(m_vNumber.at(itr));
        std::string strDigit = "";

        if (unDigit == 0)
        {
            continue;
        }

        if (itr == m_vNumber.size() - 1)
        {
            SingleDigit(itr, unDigit, strDigit);
        }

        if (itr == m_vNumber.size() - 2)
        {
            DoubleDigits(itr, unDigit, strDigit);
        }

        if (itr == m_vNumber.size() - 3)
        {
            TripleDigits(unDigit, strDigit);
        }

        if (itr == m_vNumber.size() - 4)
        {
            FourDigits(unDigit, strDigit);
        }

        vStringDigits.push_back(strDigit);
    }
}

void ToWord::PrintNumbers(const std::vector<std::string>& vStringDigits)
{
    for (const auto& aDigit : vStringDigits)
    {
        std::cout << aDigit << " ";
    }
    std::cout << "\n";
}

void ToWord::SingleDigit(std::size_t itr,
                         uint32_t unDigit,
                         std::string& strOutDigit)
{
    if (m_vNumber.size() > 1)
    {
        auto unPreviousDigit = static_cast<uint32_t>(m_vNumber.at(itr - 1));
        if (unPreviousDigit == 1)
        {
            return;
        }
    }
    strOutDigit = m_vSingleDigit.at(unDigit);
}

void ToWord::DoubleDigits(std::size_t itr,
                          uint32_t unDigit,
                          std::string& strOutDigit)
{
    if (unDigit == 1)
    {
        auto unNextDigit = static_cast<uint32_t>(m_vNumber.at(itr + 1));
        strOutDigit = m_vTen.at(unNextDigit);
    }
    else if (unDigit >= 2)
    {
        strOutDigit = m_vDoubleDigits.at(unDigit - 2);
    }
}

void ToWord::TripleDigits(uint32_t unDigit, std::string& strOutDigit)
{
    strOutDigit = m_vSingleDigit.at(unDigit);
    strOutDigit.append(" ").append(m_strHundreds);
}

void ToWord::FourDigits(uint32_t unDigit, std::string& strOutDigit)
{
    strOutDigit = m_vSingleDigit.at(unDigit);
    strOutDigit.append(" ").append(m_strThousand);
}
