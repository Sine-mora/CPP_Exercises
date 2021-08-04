#pragma once

#include <iostream>
#include "IExercise.h"

#include <vector>

class NestedVectors : public IExercise
{
public:
    NestedVectors() = default;
    ~NestedVectors() override = default;
    void RunExercise() final;
};
