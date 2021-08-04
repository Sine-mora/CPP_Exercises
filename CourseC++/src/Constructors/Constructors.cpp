#include "Constructors.h"

Mobile::Mobile(const std::string& strName,
               int nRAM,
               const std::string& strProcessor,
               int nBattery)
    : m_strName{strName}, m_strProcessor{strProcessor}, m_nRAM{nRAM}, m_nBattery{nBattery}
{
    /* m_strName = strName;
     * m_nRAM = nRAM;
     * m_strProcessor = strProcessor;
     * m_nBattery = nBattery;
     */
}

Mobile::Mobile(Mobile& mobile1)
{
    m_strName = mobile1.m_strName;
    m_strProcessor = mobile1.m_strProcessor;
    m_nRAM = mobile1.m_nRAM;
    m_nBattery = mobile1.m_nBattery;
}

void Mobile::GetMobileData()
{
    std::cout << "\nMobile's Name: " << m_strName;
    std::cout << "\nRAM: " << m_nRAM;
    std::cout << "\nProcessor: " << m_strProcessor;
    std::cout << "\nBattery: " << m_nBattery;
}

std::ostream& operator<<(std::ostream& out, const Mobile& mobile)
{
    out << "\nMobile's Name: " << mobile.m_strName << "\nRAM: " << mobile.m_nRAM
        << "\nProcessor: " << mobile.m_strProcessor << "\nBattery: " << mobile.m_nBattery;

    return out;
}
