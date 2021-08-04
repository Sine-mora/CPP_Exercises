#pragma once

#include <iostream>
#include "IExercise.h"

#include <list>

class List : public IExercise
{
public:
    List() = default;
    ~List() override = default;
    void RunExercise() final;
};
