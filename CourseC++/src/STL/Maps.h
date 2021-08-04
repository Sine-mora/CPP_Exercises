#pragma once

#include <iostream>
#include "IExercise.h"

#include <map>

class Map : public IExercise
{
public:
    Map() = default;
    ~Map() override = default;
    void RunExercise() final;
};
