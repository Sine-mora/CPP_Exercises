#pragma once

class IExercise
{
public:
    IExercise() = default;
    virtual ~IExercise() = default;
    virtual void RunExercise() = 0;
};
