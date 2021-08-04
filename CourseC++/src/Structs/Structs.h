#pragma once
#include "IExercise.h"
#include <iostream>
#include <string>

struct Camera
{
    Camera() = default;
    Camera(int nFront, int nRear);
    int m_nFront;
    int m_nRear;
    friend std::ostream& operator<<(std::ostream& out, const Camera& obj);
};

struct Phone : public IExercise
{
    Phone() = default;
    Phone(const std::string& strName,
          int nRAM,
          int nROM,
          const std::string& strProcessor,
          const Camera& camera);

    std::string m_strName;
    int m_nRAM;
    int m_nROM;
    std::string m_strProcessor;
    Camera m_cCamera;
    void RunExercise() override;
    friend std::ostream &operator<<(std::ostream& out, const Phone& obj);
};

struct Student : public IExercise
{
    Student();
    std::string m_strFullname;
    int m_nID;
    int m_nMarks;
    void PrintData();
    void RunExercise() final;
};
