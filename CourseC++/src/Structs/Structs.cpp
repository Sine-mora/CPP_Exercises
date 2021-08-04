#include "Structs.h"

Camera::Camera(int nFront, int nRear) : m_nFront{nFront}, m_nRear{nRear}
{
}

std::ostream& operator<<(std::ostream& out, const Camera& obj)
{
    out << "\nCamera Rear: " << obj.m_nRear << "\nCamera Front: " << obj.m_nFront << "\n";
    return out;
}

Phone::Phone(const std::string& strName,
             int nRAM,
             int nROM,
             const std::string& strProcessor,
             const Camera& camera)
    : m_strName{strName}, m_nRAM{nRAM}, m_nROM{nROM}, m_strProcessor{strProcessor},
      m_cCamera{camera}
{
}

void Phone::RunExercise()
{
    std::cout << "\nPhone's RunExercise\n";
}

std::ostream& operator<<(std::ostream& out, const Phone& obj)
{
    out << "\nPhone's name: " << obj.m_strName << "\nRAM: " << obj.m_nRAM
        << "\nROM: " << obj.m_nROM << "\nProcessor: " << obj.m_strProcessor
        << "\nCameran Diaz: " << obj.m_cCamera;

    return out;
}

void Student::PrintData()
{
    std::cout << "\n Student's name: " << m_strFullname << "\n Student's Id: " << m_nID
              << "\n Student's marks: " << m_nMarks << "\n";
}

void Student::RunExercise()
{
    std::cout << "\nStudent's RunExercise:\n";
}

Student::Student() : m_strFullname{"Petko Petkov"}, m_nID{34}, m_nMarks{100}
{
}
