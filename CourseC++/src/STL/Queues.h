#pragma once

#include <iostream>
#include "IExercise.h"

#include <queue>

class Queue : public IExercise
{
public:
    Queue() = default;
    ~Queue() override = default;
    void RunExercise() final;
};
