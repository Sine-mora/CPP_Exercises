#pragma once
#include "IExercise.h"

class Loops : public IExercise
{
public:
    Loops() = default;
    ~Loops() override = default;
    void FindSum();
    void RunExercise() final;

private:
};
