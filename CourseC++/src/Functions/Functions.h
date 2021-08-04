#pragma once
#include "IExercise.h"
#include <iostream>
#include <vector>

class Functions : public IExercise
{
public:
    Functions() = default;
    ~Functions() override = default;
    void RunExercise() final;
    bool IsOdd(uint32_t unNumber);
    bool IsArmstrong(uint32_t unNumber);
};
