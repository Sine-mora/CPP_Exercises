#include "Interpolator.h"

namespace Easing
{
template <typename T>
void Interpolator<T>::Start(const T& begin, const T& end,
                            float duration, EFunctions eFunc)
{
    m_current = begin;
    m_begin = begin;
    m_end = end;
    m_fDuration = duration;
    m_funcType = GetEasingFunc(eFunc);
    m_fElapsedTime = 0.0;
    m_isReady = false;
}

template <typename T>
const T& Interpolator<T>::Update(float fDeltaTime)
{
    /** Increment elapsed time. */
    m_fElapsedTime += fDeltaTime;

    /** Normalize time in range [0, 1]. */
    double fT= m_fElapsedTime / m_fDuration;

    /** Check if m_funType is valid. */
    double dProgress = 0.0;
    if (m_funcType)
    {
        /** Calculate current progress in range [0, 1]. */
        dProgress = m_funcType(fT);
    }

    /** Calculate m_current, based on dProgress. */
    m_current = ((m_end - m_begin) * dProgress) + m_begin;

    /** Check if the interpolation is ready. */
    if (m_fElapsedTime >= m_fDuration)
    {
        m_current = m_end;
        m_isReady = true;
    }

    return m_current;
}

template <typename T>
bool Interpolator<T>::IsReady() const
{
    return m_isReady;
}
} // namespace Easing
