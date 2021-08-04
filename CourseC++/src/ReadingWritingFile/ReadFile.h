#pragma once

#include <fstream>
#include <iostream>
#include "IExercise.h"

class ReadFromFile : public IExercise
{
private:
    std::ifstream m_inStream;
    char m_ch;

public:
    ReadFromFile() = default;
    ~ReadFromFile() override = default;
    void RunExercise() final;
    bool Read(const std::string& strFileLocation = "TestingFile.txt");
};
