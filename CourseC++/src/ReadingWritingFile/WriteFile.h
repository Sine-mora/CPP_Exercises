#pragma once

#include <fstream>
#include <iostream>
#include "IExercise.h"

class WriteToFile : public IExercise
{
private:
    std::ofstream fout;

public:
    WriteToFile() = default;
    ~WriteToFile() override = default;
    void RunExercise() final;
    void Write(const std::string& strFileLocation);
};
