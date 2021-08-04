#pragma once

#include <iostream>
#include "IExercise.h"

#include <array>

class STDArray : public IExercise
{
public:
    STDArray() = default;
    ~STDArray() override = default;
    void RunExercise() final;
};
