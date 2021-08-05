#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstring>
#include <iostream>
#include <string>
#include "Utils/Timer.h"
#include "StateMachine/StateManager.h"
#include "StateMachine/GameMenuState.h"
#include "StateMachine/MovingDownState.h"
#include "StateMachine/MovingLeftState.h"
#include "StateMachine/MovingRightState.h"
#include "StateMachine/MovingUpState.h"

class GameLoop : public IExercise
{
public:
    GameLoop();
    ~GameLoop() override = default;
    void RunExercise() final;
    bool IsRunning() const;
    bool Initialize(
        const char* strTitle, int nX, int nY, int nWidth, int nHeight, Uint32 flags);
    bool LoadImage();
    void CheckPos(float deltaTime);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();

    SDL_Rect& GetTextureRect();
    SDL_Point& GetProjectileVelocity();
    SDL_Point& GetWindowDimensions();

private:
    std::string GetCurrWorkingDir() const;
private:
    StateManager m_stateManager;
    SDL_Window* m_window;
    SDL_Event m_event;
    SDL_Renderer* m_renderer;
    SDL_Texture *m_image;
    SDL_Rect& m_textureRect;
    SDL_Point& m_ProjectileVelocity;

    const std::string m_strImagePath;
    int m_nTextureWidth, m_nTextureHeight;

    const unsigned int m_FPS;
    const unsigned int m_FRAME_TARGET_TIME;
    int m_nTicksLastFrame;
    //int m_nWindowHeight, m_nWindowWidth;
    bool m_hasNotReachedEndX;
    bool m_hasNotReachedEndY;
  //short m_sAmountOfFood;
  //short m_sAmountOfSpikes;
    bool m_isRunning;
};
