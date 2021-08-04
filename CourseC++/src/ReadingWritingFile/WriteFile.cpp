#include "WriteFile.h"

void WriteToFile::Write(const std::string& strFileLocation = "TestingFile.txt")
{
    fout.open(strFileLocation);

    fout << "\nThis line was inserted via the program.\n";

    fout.close();
}

void WriteToFile::RunExercise()
{
    Write();
}
