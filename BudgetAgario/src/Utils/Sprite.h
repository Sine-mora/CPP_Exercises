#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Utils/Interpolator.hpp"

// Arithmetic operations on point
inline SDL_Rect operator+(const SDL_Rect& lhs, const SDL_Rect& rhs)
{
    SDL_Rect ret;
    ret.x = lhs.x + rhs.x;
    ret.y = lhs.y + rhs.y;
    ret.w = lhs.w + rhs.w;
    ret.h = lhs.h + rhs.h;
    return ret;
}

inline SDL_Rect operator-(const SDL_Rect& lhs, const SDL_Rect& rhs)
{
    SDL_Rect ret;
    ret.x = lhs.x - rhs.x;
    ret.y = lhs.y - rhs.y;
    ret.w = lhs.w - rhs.w;
    ret.h = lhs.h - rhs.h;
    return ret;
}

template <typename S>
inline typename std::enable_if<std::is_arithmetic<S>::value, SDL_Rect>::type
operator+(const SDL_Rect& lhs, const S& rhs)
{
    SDL_Rect ret;
    ret.x = lhs.x + rhs;
    ret.y = lhs.y + rhs;
    ret.w = lhs.w + rhs;
    ret.h = lhs.h + rhs;
    return ret;
}

template <typename S>
inline typename std::enable_if<std::is_arithmetic<S>::value, SDL_Rect>::type
operator-(const SDL_Rect& lhs, const S& rhs)
{
    SDL_Rect ret;
    ret.x = lhs.x - rhs;
    ret.y = lhs.y - rhs;
    ret.w = lhs.w - rhs;
    ret.h = lhs.h - rhs;
    return ret;
}

template <typename S>
inline typename std::enable_if<std::is_arithmetic<S>::value, SDL_Rect>::type
operator*(const SDL_Rect& lhs, const S& rhs)
{
    SDL_Rect ret;
    ret.x = lhs.x * rhs;
    ret.y = lhs.y * rhs;
    ret.w = lhs.w * rhs;
    ret.h = lhs.h * rhs;
    return ret;
}

/**
 * @brief The Sprite struct - interactive texture. */
struct Sprite
{
    /** Sprite texture. */
    SDL_Texture* m_texture{nullptr};

    /** Destination rect - where to be drawn on the screen. */
    SDL_Rect m_destRect{};

    /** Interpolator for x. */
    Easing::Interpolator<int> m_interX{};

    /** Interpolator for y. */
    Easing::Interpolator<int> m_interY{};

    Easing::Interpolator<SDL_Rect> m_interRect{};

    /**
     * @brief Load - load a sprite texture.
     * @param ptrRend - renderer, used to load the texture.
     * @param strPath - path to the sprite texture.
     * @return true, if the sprite was loaded successfully. */
    bool Load(SDL_Renderer* ptrRend, const std::string& strPath);

    /**
     * @brief Draw - draw the sprite texture.
     * @param ptrRend - renderer, used to draw this sprite. */
    void Draw(SDL_Renderer* ptrRend);

    /**
     * @brief Start - start interpolating the sprite from posStart to posEnd.
     * @param posStart - start point of the interpolation.
     * @param posEnd - end point of the interpolation.
     * @param dDuration - duration of the interpolation in seconds.
     * @param eFuncType - interpolation function type. */
    void Start(const SDL_Point& posStart,
               const SDL_Point& posEnd,
               float fDuration,
               Easing::EFunctions eFuncType = Easing::EFunctions::eEaseLinear);

    /**
     * @brief Start - start interpolating the sprite from posStart to posEnd.
     * @param rectStart - start rect of the interpolation.
     * @param rectEnd - end rect of the interpolation.
     * @param dDuration - duration of the interpolation in seconds.
     * @param eFuncType - interpolation function type. */
    void Start(const SDL_Rect& rectStart,
               const SDL_Rect& rectEnd,
               float fDuration,
               Easing::EFunctions eFuncType = Easing::EFunctions::eEaseLinear);

    /**
     * @brief Update - update the sprite.
     * @param fDeltaTime - delta time in seconds. */
    void Update(float fDeltaTime);

    void ResetDestRect();
private:
    SDL_Rect m_destRectOriginal{};
};


