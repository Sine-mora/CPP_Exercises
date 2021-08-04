#pragma once

#include "IExercise.h"
#include <iostream>
#include <string>

class TemplateFuncExample : public IExercise
{
public:
    TemplateFuncExample() = default;
    ~TemplateFuncExample() override = default;
    void RunExercise() final;
    //void IntSum(int x , int y );
    //void Sum(float x = 3, float y = 4);
   //void Sum(double x = 3, double y = 4);
   // void Sum(const std::string& x = "X ", const std::string& y = "Y");

    template <class T> T Sum(T x, T y);
};

template<class T>
class TemplateClassExample : public IExercise
{
public:
    T var1;
    T var2;
    TemplateClassExample() = default;
    ~TemplateClassExample() override = default;
    void RunExercise() final;
    void Add();
};
