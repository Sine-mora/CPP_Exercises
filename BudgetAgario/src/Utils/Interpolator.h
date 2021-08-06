#pragma once
#include "EasingFunctions.h"

namespace Easing
{
template <typename T>
class Interpolator
{
public:
    /** Default constructor. */
    Interpolator() = default;
    virtual ~Interpolator() = default;

    /**
     * @brief Start - Start interpolating
     * @param begin - initial value of the interpolation.
     * @param end - target value of the interpolation.
     * @param duration - duration of the interpolation in seconds.
     * @param eFuncType - function type, used to calculate m_current. */
    void Start(const T& begin, const T& end, float duration, EFunctions eFunc);

    /**
     * @brief Update - update the interpolation value, based on the current delta time.
     * @param fDeltaTime - current delta time in seconds. */
    const T& Update(float fDeltaTime);

    /**
     * @brief IsReady - query whether the interpolator is ready.
     * @return m_isReady. */
    bool IsReady() const;


private:
    /** Current value, being interpolated. */
    T m_current{};

    /** Initial value of the interpolation. */
    T m_begin{};

    /** Target value of the interpolation. */
    T m_end{};

    /** Duration of the interpolation in seconds. */
    double m_fDuration{0.0};

    /** Easing function, used to calculate m_current. */
    FuncType m_funcType{};

    /** Current time in seconds since the interpolator has been started. */
    float m_fElapsedTime{0.0};
    /**
     * @brief m_isReady - is the interpolator ready. */
    bool m_isReady = true;
};
} // name
