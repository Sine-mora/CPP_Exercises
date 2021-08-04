#include "ReadFile.h"

bool ReadFromFile::Read(const std::string& strFileLocation)
{
    // TODO Check if file exist

    m_inStream.open(strFileLocation);

    if (!m_inStream.is_open())
    {
        std::cout << "\nError Opening strFileLocation.\n" << strFileLocation;
        return false;
    }

    while (!m_inStream.eof())
    {
        m_inStream >> std::noskipws >> m_ch;
        std::cout << m_ch;
    }

    m_inStream.close();
    return true;
}

void ReadFromFile::RunExercise()
{
    if (!Read())
    {
        std::cout << "\nFailed to Run Exercise.\n";
    }
}
