#pragma once

#include <iostream>
#include "IExercise.h"

#include <list>

class NestedLists : public IExercise
{
public:
    NestedLists() = default;
    ~NestedLists() override = default;
    void RunExercise() final;
};
