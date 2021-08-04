#pragma once

#include <iostream>
#include "IExercise.h"

#include <queue>

class PriorityQueue : public IExercise
{
public:
    PriorityQueue() = default;
    ~PriorityQueue() override = default;
    void RunExercise() final;
};
