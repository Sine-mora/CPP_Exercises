#pragma once

#include <iostream>
#include "IExercise.h"

#include <unordered_set>

class UnorderedSet :public IExercise
{
public:
    UnorderedSet() = default;
    ~UnorderedSet() override = default;
    void RunExercise() final;
};
