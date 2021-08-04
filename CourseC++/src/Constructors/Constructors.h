#pragma once

#include <iostream>
#include <string>

class Mobile
{
public:
    Mobile(const std::string& strName = "N/A",
           int nRAM = 0,
           const std::string& strProcessor = "N/A",
           int nBattery = 0);
    Mobile(Mobile& mobile2);
    ~Mobile() = default;
    void GetMobileData();

    friend std::ostream& operator<<(std::ostream& out, const Mobile& mobile);

private:
    std::string m_strName;
    std::string m_strProcessor;
    int m_nRAM;
    int m_nBattery;
};
