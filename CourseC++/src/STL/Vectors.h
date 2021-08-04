#pragma once

#include <iostream>
#include "IExercise.h"

#include <vector>

class Vector :public IExercise
{
public :
    Vector() = default;
    ~Vector() override = default;
    void RunExercise() final;
};
