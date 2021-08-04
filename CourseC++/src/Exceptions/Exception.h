#pragma once

#include <iostream>
#include "IExercise.h"

class Exception : public IExercise
{
public:
    Exception() = default;
    ~Exception() override = default;
    void RunExercise() final;
};
