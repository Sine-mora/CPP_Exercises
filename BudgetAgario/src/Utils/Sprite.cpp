#include "Sprite.h"

bool Sprite::Load(SDL_Renderer* ptrRend, const std::string& strPath)
{
    m_texture = IMG_LoadTexture(ptrRend, strPath.c_str());
    if (!m_texture)
    {
        std::cerr << " failed to load texture: " << strPath << "\n";
        return false;
    }
    SDL_QueryTexture(m_texture, NULL, NULL, &m_destRect.w, &m_destRect.h);

    m_destRectOriginal = m_destRect;
    std::cout << " x: " << m_destRect.x << ", y: " << m_destRect.y
              << ", w: " << m_destRect.w << ", h: " << m_destRect.h << "\n";
    return true;
}

void Sprite::Draw(SDL_Renderer* ptrRend)
{
    SDL_RenderCopy(ptrRend, m_texture, nullptr, &m_destRect);
}

void Sprite::Start(const SDL_Point& posStart,
                   const SDL_Point& posEnd,
                   float fDuration,
                   Easing::EFunctions eFuncType)
{
    SDL_Rect rectBegin{posStart.x, posStart.y, m_destRect.w, m_destRect.h};
    SDL_Rect rectEnd{posEnd.x, posEnd.y, m_destRect.w, m_destRect.h};
    m_interRect.Start(rectBegin, rectEnd, fDuration, eFuncType);
}

void Sprite::Start(const SDL_Rect& rectStart,
                   const SDL_Rect& rectEnd,
                   float fDuration,
                   Easing::EFunctions eFuncType)
{
    m_interRect.Start(rectStart, rectEnd, fDuration, eFuncType);
}

void Sprite::Update(float fDeltaTime)
{
    if (!m_interRect.IsReady())
    {
        m_destRect = m_interRect.Update(fDeltaTime);
    }
}

void Sprite::ResetDestRect()
{
    m_destRect = m_destRectOriginal;
}
