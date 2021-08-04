#pragma once

#include <iostream>
#include "IExercise.h"

#include <unordered_map>

class UnorderedMap : public IExercise
{
public:
    UnorderedMap() = default;
    ~UnorderedMap() override = default;
    void RunExercise() final;
};
