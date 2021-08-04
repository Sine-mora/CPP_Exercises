#pragma once

#include <iostream>
#include "IExercise.h"

#include <stack>

class Stack : public IExercise
{
public:
    Stack() = default;
    ~Stack() override = default;
    void RunExercise() final;
};
