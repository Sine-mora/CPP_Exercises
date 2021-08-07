#include "EasingFunctions.h"
#include <unordered_map>

namespace Easing
{
namespace
{
constexpr float pi = 3.14159265358979323846f;
constexpr float half_pi = pi * 0.5f;

float linearInterpolation(float a)
{
    return a;
}

float quadraticEaseIn(float a)
{
    return a * a;
}

float quadraticEaseOut(float a)
{
    return -(a * (a - static_cast<float>(2)));
}

float quadraticEaseInOut(float a)
{
    if(a < static_cast<float>(0.5))
    {
        return static_cast<float>(2) * a * a;
    }

    return (-static_cast<float>(2) * a * a) + (4 * a) - 1.0f;
}

float cubicEaseIn(float a)
{
    return a * a * a;
}

float cubicEaseOut(float a)
{
    float const f = a - 1.0f;
    return f * f * f + 1.0f;
}

float cubicEaseInOut(float a)
{
    if (a < static_cast<float>(0.5))
    {
        return static_cast<float>(4) * a * a * a;
    }

    float const f = ((static_cast<float>(2) * a) - static_cast<float>(2));
    return static_cast<float>(0.5) * f * f * f + 1.0f;
}

float quarticEaseIn(float a)
{
    return a * a * a * a;
}

float quarticEaseOut(float a)
{
    float const f = (a - 1.0f);
    return f * f * f * (1.0f - a) + 1.0f;
}

float quarticEaseInOut(float a)
{
    if(a < static_cast<float>(0.5))
    {
        return static_cast<float>(8) * a * a * a * a;
    }

    float const f = (a - 1.0f);
    return -static_cast<float>(8) * f * f * f * f + 1.0f;
}

float quinticEaseIn(float a)
{
    return a * a * a * a * a;
}

float quinticEaseOut(float a)
{
    float const f = (a - 1.0f);
    return f * f * f * f * f + 1.0f;
}

float quinticEaseInOut(float a)
{
    if(a < static_cast<float>(0.5))
    {
        return static_cast<float>(16) * a * a * a * a * a;
    }

    float const f = ((static_cast<float>(2) * a) - static_cast<float>(2));
    return static_cast<float>(0.5) * f * f * f * f * f + 1.0f;
}

float sineEaseIn(float a)
{
    return std::sin((a - 1.0f) * half_pi) + 1.0f;
}

float sineEaseOut(float a)
{
    return std::sin(a * half_pi);
}

float sineEaseInOut(float a)
{
    return static_cast<float>(0.5) * (1.0f - std::cos(a * static_cast<float>(pi)));
}

float circularEaseIn(float a)
{
    return 1.0f - std::sqrt(1.0f - (a * a));
}

float circularEaseOut(float a)
{
    return std::sqrt((static_cast<float>(2) - a) * a);
}

float circularEaseInOut(float a)
{
    if(a < static_cast<float>(0.5))
    {
        return static_cast<float>(0.5) * (1.0f - std::sqrt(1.0f - static_cast<float>(4) * (a * a)));
    }

    return static_cast<float>(0.5) * (std::sqrt(-((static_cast<float>(2) * a) - static_cast<float>(3)) * ((static_cast<float>(2) * a) - 1.0f)) + 1.0f);
}

float exponentialEaseIn(float a)
{
    if(a <= 0.0f)
    {
        return a;
    }

    float const Complementary = a - 1.0f;
    float const Two = 2.0f;

    return std::pow(Two, Complementary * static_cast<float>(10));
}

float exponentialEaseOut(float a)
{
    if(a >= 1.0f)
    {
        return a;
    }

    return 1.0f - std::pow(static_cast<float>(2), -static_cast<float>(10) * a);
}

float exponentialEaseInOut(float a)
{
    if(a < static_cast<float>(0.5))
    {
        return static_cast<float>(0.5) * std::pow(static_cast<float>(2), (static_cast<float>(20) * a) - static_cast<float>(10));
    }

    return -static_cast<float>(0.5) * std::pow(static_cast<float>(2), (-static_cast<float>(20) * a) + static_cast<float>(10)) + 1.0f;
}

float elasticEaseIn(float a)
{
    return std::sin(static_cast<float>(13) * half_pi * a) * std::pow(static_cast<float>(2), static_cast<float>(10) * (a - 1.0f));
}

float elasticEaseOut(float a)
{
    return std::sin(-static_cast<float>(13) * half_pi * (a + 1.0f)) * std::pow(static_cast<float>(2), -static_cast<float>(10) * a) + 1.0f;
}

float elasticEaseInOut(float a)
{
    if(a < static_cast<float>(0.5))
    {
        return static_cast<float>(0.5) * std::sin(static_cast<float>(13) * half_pi * (static_cast<float>(2) * a)) * std::pow(static_cast<float>(2), static_cast<float>(10) * ((static_cast<float>(2) * a) - 1.0f));
    }

    return static_cast<float>(0.5) * (std::sin(-static_cast<float>(13) * half_pi * ((static_cast<float>(2) * a - 1.0f) + 1.0f)) * std::pow(static_cast<float>(2), -static_cast<float>(10) * (static_cast<float>(2) * a - 1.0f)) + static_cast<float>(2));
}

float backEaseIn(float a, float const& o)
{
    float z = ((o + 1.0f) * a) - o;
    return (a * a * z);
}

float backEaseOut(float a, float const& o)
{
    float n = a - 1.0f;
    float z = ((o + 1.0f) * n) + o;
    return (n * n * z) + 1.0f;
}

float backEaseInOut(float a, float const& o)
{
    float s = o * static_cast<float>(1.525);
    float x = 0.5f;
    float n = a / static_cast<float>(0.5);

    if (n < static_cast<float>(1))
    {
        float z = ((s + static_cast<float>(1)) * n) - s;
        float m = n * n * z;
        return x * m;
    }

    n -= static_cast<float>(2);
    float z = ((s + static_cast<float>(1)) * n) + s;
    float m = (n*n*z) + static_cast<float>(2);
    return x * m;
}

float backEaseIn(float a)
{
    return backEaseIn(a, static_cast<float>(1.70158));
}

float backEaseOut(float a)
{
    return backEaseOut(a, static_cast<float>(1.70158));
}

float backEaseInOut(float a)
{
    return backEaseInOut(a, static_cast<float>(1.70158));
}

float bounceEaseOut(float a)
{
    if(a < static_cast<float>(4.0 / 11.0))
    {
        return (static_cast<float>(121) * a * a) / static_cast<float>(16);
    }
    if(a < static_cast<float>(8.0 / 11.0))
    {
        return (static_cast<float>(363.0 / 40.0) * a * a) - (static_cast<float>(99.0 / 10.0) * a) + static_cast<float>(17.0 / 5.0);
    }
    if(a < static_cast<float>(9.0 / 10.0))
    {
        return (static_cast<float>(4356.0 / 361.0) * a * a) - (static_cast<float>(35442.0 / 1805.0) * a) + static_cast<float>(16061.0 / 1805.0);
    }
    return (static_cast<float>(54.0 / 5.0) * a * a) - (static_cast<float>(513.0 / 25.0) * a) + static_cast<float>(268.0 / 25.0);
}

float bounceEaseIn(float a)
{
    return 1.0f - bounceEaseOut(1.0f - a);
}

float bounceEaseInOut(float a)
{
    if(a < static_cast<float>(0.5))
    {
        return static_cast<float>(0.5) * (1.0f - bounceEaseOut(a * static_cast<float>(2)));
    }

    return static_cast<float>(0.5) * bounceEaseOut(a * static_cast<float>(2) - 1.0f) + static_cast<float>(0.5);
}

} //end of anonymous namespace

static const FuncType easeLinear = [](float fT)
{
    return linearInterpolation(fT);
};

static const FuncType easeInSine = [](float fT)
{
    return sineEaseIn(fT);
};

    static const FuncType easeOutSine = [](float fT)
    {
        return sineEaseOut(fT);
    };

        static const FuncType easeInOutSine = [](float fT)
        {
            return sineEaseInOut(fT);
        };

static const FuncType easeInQuad = [](float fT)
{
    return quadraticEaseIn(fT);
};

    static const FuncType easeOutQuad = [](float fT)
    {
        return quadraticEaseOut(fT);
    };

        static const FuncType easeInOutQuad = [](float fT)
        {
            return quadraticEaseInOut(fT);
        };

static const FuncType easeInCubic = [](float fT)
{
    return cubicEaseIn(fT);
};

    static const FuncType easeOutCubic = [](float fT)
    {
        return cubicEaseOut(fT);
    };

        static const FuncType easeInOutCubic = [](float fT)
        {
            return cubicEaseInOut(fT);
        };

static const FuncType easeInQuart = [](float fT)
{
    return quarticEaseIn(fT);
};

    static const FuncType easeOutQuart = [](float fT)
    {
        return quarticEaseOut(fT);
    };

        static const FuncType easeInOutQuart = [](float fT)
        {
            return quarticEaseInOut(fT);
        };

static const FuncType easeInQuint = [](float fT)
{
    return quinticEaseIn(fT);
};

    static const FuncType easeOutQuint = [](float fT)
    {
        return quinticEaseOut(fT);
    };

        static const FuncType easeInOutQuint = [](float fT)
        {
            return quinticEaseInOut(fT);
        };

static const FuncType easeInExpo = [](float fT)
{
    return exponentialEaseIn(fT);
};

    static const FuncType easeOutExpo = [](float fT)
    {
        return exponentialEaseOut(fT);
    };

        static const FuncType easeInOutExpo = [](float fT)
        {
            return exponentialEaseInOut(fT);
        };

static const FuncType easeInCirc = [](float fT)
{
    return circularEaseIn(fT);
};

    static const FuncType easeOutCirc = [](float fT)
    {
        return circularEaseOut(fT);
    };

        static const FuncType easeInOutCirc = [](float fT)
        {
            return circularEaseInOut(fT);
        };

static const FuncType easeInBack = [](float fT)
{
    return backEaseIn(fT);
};

    static const FuncType easeOutBack = [](float fT)
    {
        return backEaseOut(fT);
    };

        static const FuncType easeInOutBack = [](float fT)
        {
            return backEaseInOut(fT);
        };

static const FuncType easeInElastic = [](float fT)
{
    return elasticEaseIn(fT);
};

    static const FuncType easeOutElastic = [](float fT)
    {
        return elasticEaseOut(fT);
    };

        static const FuncType easeInOutElastic = [](float fT)
        {
            return elasticEaseInOut(fT);
        };

static const FuncType easeInBounce = [](float fT)
{
    return bounceEaseIn(fT);
};

    static const FuncType easeOutBounce = [](float fT)
    {
        return bounceEaseOut(fT);
    };

        static const FuncType easeInOutBounce = [](float fT)
        {
            return bounceEaseInOut(fT);
        };

const FuncType& GetEasingFunc(EFunctions eFunction)
{
    static const std::unordered_map<EFunctions, FuncType> s_mapFuncs
    {
            { EFunctions::eEaseLinear, easeLinear},

            { EFunctions::eEaseInSine, easeInSine},
            { EFunctions::eEaseOutSine, easeOutSine},
            { EFunctions::eEaseInOutSine, easeInOutSine},

            { EFunctions::eEaseInQuad, easeInQuad},
            { EFunctions::eEaseOutQuad, easeOutQuad},
            { EFunctions::eEaseInOutQuad, easeInOutQuad},

            { EFunctions::eEaseInCubic, easeInCubic},
            { EFunctions::eEaseOutCubic, easeOutCubic},
            { EFunctions::eEaseInOutCubic, easeInOutCubic},

            { EFunctions::eEaseInQuart, easeInQuart},
            { EFunctions::eEaseOutQuart, easeOutQuart},
            { EFunctions::eEaseInOutQuart, easeInOutQuart},

            { EFunctions::eEaseInQuint, easeInQuint},
            { EFunctions::eEaseOutQuint, easeOutQuint},
            { EFunctions::eEaseInOutQuint, easeInOutQuint},

            { EFunctions::eEaseInExpo, easeInExpo},
            { EFunctions::eEaseOutExpo, easeOutExpo},
            { EFunctions::eEaseInOutExpo, easeInOutExpo},

            { EFunctions::eEaseInCirc, easeInCirc},
            { EFunctions::eEaseOutCirc, easeOutCirc},
            { EFunctions::eEaseInOutCirc, easeInOutCirc},

            { EFunctions::eEaseInBack, easeInBack},
            { EFunctions::eEaseOutBack, easeOutBack},
            { EFunctions::eEaseInOutBack, easeInOutBack},

            { EFunctions::eEaseInElastic, easeInElastic},
            { EFunctions::eEaseOutElastic, easeOutElastic},
            { EFunctions::eEaseInOutElastic, easeInOutElastic},

            { EFunctions::eEaseInBounce, easeInBounce},
            { EFunctions::eEaseOutBounce, easeOutBounce},
            { EFunctions::eEaseInOutBounce, easeInOutBounce}
    };
    const auto& it = s_mapFuncs.find(eFunction);
    if (it != s_mapFuncs.end())
    {
        return it->second;
    }
    return easeLinear;
}

} // namespace Easing
