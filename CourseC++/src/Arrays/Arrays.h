#pragma once
#include "IExercise.h"
#include <iostream>
#include <array>

class Arrays : public IExercise
{
public:
    Arrays() = default;
    ~Arrays() = default;
    void RunExercise() final;
};
