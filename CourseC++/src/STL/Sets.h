#pragma once

#include <iostream>
#include "IExercise.h"

#include <set>

class Set :public IExercise
{
public:
    Set() = default;
    ~Set() override = default;
    void RunExercise() final;
};
