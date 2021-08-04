#pragma once

#include <iostream>
#include "IExercise.h"

#include <map>

class MultiMap : public IExercise
{
public:
    MultiMap() = default;
    ~MultiMap() override = default;
    void RunExercise() final;
};
