#pragma once

#include <iostream>
#include "IExercise.h"

#include <map>

class MapInMap : public IExercise
{
public:
    MapInMap() = default;
    ~MapInMap() override = default;
    void RunExercise() final;
};
