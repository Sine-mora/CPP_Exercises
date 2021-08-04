#pragma once

#include <iostream>
#include "IExercise.h"

#include <set>

class MultiSet : public IExercise
{
public:
    MultiSet() = default;
    ~MultiSet() override = default;
    void RunExercise() final;
};
