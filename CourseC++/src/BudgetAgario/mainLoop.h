#pragma once

#include "IExercise.h"
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
    GameLoop() = default;
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

private:
    StateManager m_stateManager;
//    Timer m_timer = Timer::Get();
    SDL_Window* m_window;
   // SDL_Event m_event;
    SDL_Renderer* m_renderer;
    SDL_Texture *m_image;
    SDL_Rect m_textureRect;
    int m_nTextureWidth, m_nTextureHeight;
    const std::string m_strImagePath = "../assets/foxy_fox.png";

    float m_fProjectilePosX = 0.0f, m_fProjectilePosY = 0.0f;
    float m_fProjectileVelX = 240.5f, m_fProjectileVelY = 100.3f;
    float m_fWidth = 10, m_fHeight = 10;
    const unsigned int m_FPS = 60;
    const unsigned int m_FRAME_TARGET_TIME = 1000 / m_FPS;
    int m_nTicksLastFrame = 0;
    int m_nWindowHeight = 600;
    int m_nWindowWidth = 800;
    bool m_hasNotReachedEndX = true;
    bool m_hasNotReachedEndY = true;

    short m_sAmountOfFood;
    short m_sAmountOfSpikes;
    char m_cInput;
    bool m_isRunning;
};
