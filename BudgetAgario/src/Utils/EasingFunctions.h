#pragma once
#include <functional>
#include <cmath>

namespace Easing
{
/**
 * @brief The EFunctions enum - enumerate easing function types. */
enum class EFunctions
{
    eEaseLinear,
    eEaseInSine,
    eEaseOutSine,
    eEaseInOutSine,
    eEaseInQuad,
    eEaseOutQuad,
    eEaseInOutQuad,
    eEaseInCubic,
    eEaseOutCubic,
    eEaseInOutCubic,
    eEaseInQuart,
    eEaseOutQuart,
    eEaseInOutQuart,
    eEaseInQuint,
    eEaseOutQuint,
    eEaseInOutQuint,
    eEaseInExpo,
    eEaseOutExpo,
    eEaseInOutExpo,
    eEaseInCirc,
    eEaseOutCirc,
    eEaseInOutCirc,
    eEaseInBack,
    eEaseOutBack,
    eEaseInOutBack,
    eEaseInElastic,
    eEaseOutElastic,
    eEaseInOutElastic,
    eEaseInBounce,
    eEaseOutBounce,
    eEaseInOutBounce
};

/** Easing function type. Calculate a progress value in the range [0, 1].
 * Accepts the current progress also in the range [0, 1]. */
using FuncType = std::function<float(float)>;

/**
 * @brief GetEasingFunc - retrive an easing interpolation function,
 * based on the provided enum key.
 * @param eFunction - easing function key.
 * @return an easing interpolation function, based on the provided key. */
const FuncType& GetEasingFunc(EFunctions eFunction);
}

