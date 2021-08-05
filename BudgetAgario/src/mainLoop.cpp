#include "mainLoop.h"

#ifdef __linux__
#include <unistd.h>
#elif _WIN32
// windows code goes here
#else

#endif

GameLoop::GameLoop()
    : m_stateManager{}, m_window{nullptr}, m_event{}, m_renderer{nullptr},
      m_image{nullptr}, m_textureRect{GetTextureRect()},
      m_ProjectileVelocity{GetProjectileVelocity()},
      m_strImagePath{"../assets/foxy_fox.png"}, m_nTextureWidth{0}, m_nTextureHeight{0},
      m_FPS{60}, m_FRAME_TARGET_TIME{1000 / m_FPS}, m_nTicksLastFrame{0},
      m_hasNotReachedEndX{true}, m_hasNotReachedEndY{true}, m_isRunning{false}
{
}

SDL_Rect& GameLoop::GetTextureRect()
{
    return SharedData::Get().GetRect();
}

SDL_Point& GameLoop::GetProjectileVelocity()
{
    return SharedData::Get().GetProjectileVelocity();
}

SDL_Point& GameLoop::GetWindowDimensions()
{
    return SharedData::Get().GetWindowDimensions();
}

void GameLoop::RunExercise()
{
    if (!Initialize("This is the first window",
                    SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED,
                    GetWindowDimensions().x,
                    GetWindowDimensions().y,
                    SDL_WINDOW_SHOWN))
    {
        std::cerr << " failed to init, try again another day.";
        return;
    }

    m_stateManager.ChangeState(EState::eGameMenuState);

    while (IsRunning())
    {
        ProcessInput();
        Update();
        Render();
    }
    Destroy();
}

bool GameLoop::IsRunning() const
{
    return this->m_isRunning;
}

bool GameLoop::LoadImage()
{

    std::cout << " GetCurrWorkingDir(): " << GetCurrWorkingDir();
    m_image = IMG_LoadTexture(m_renderer, m_strImagePath.c_str());
    if (!m_image)
    {
        std::cerr << " failed to load texture: " << m_strImagePath << "\n";
        return false;
    }
    SDL_QueryTexture(m_image, NULL, NULL, &m_nTextureWidth, &m_nTextureHeight);

    m_textureRect.x = 0;
    m_textureRect.y = 0;
    m_textureRect.w = m_nTextureWidth / 2;
    m_textureRect.h = m_nTextureHeight / 2;

    std::cout << " x: " << m_textureRect.x << ", y: " << m_textureRect.y
              << ", w: " << m_textureRect.w << ", h: " << m_textureRect.h << "\n";
    return true;
}

bool GameLoop::Initialize(
    const char* strTitle, int nX, int nY, int nWidth, int nHeight, Uint32 flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error initializing SDL!\n";
        return false;
    }

    m_window = SDL_CreateWindow(strTitle, nX, nY, nWidth, nHeight, flags);

    if (!m_window)
    {
        std::cerr << "Error Creating Window! " << SDL_GetError() << "\n";
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, 0);

    if (!m_renderer)
    {
        std::cerr << "Error Creating Renderer!\n";
        return false;
    }

    if (!LoadImage())
    {
        std::cerr << " image go brrr :P";
        return false;
    }

    m_stateManager.RegisterState(new GameMenuState(&m_stateManager));
    m_stateManager.RegisterState(new MovingUpState(&m_stateManager));
    m_stateManager.RegisterState(new MovingDownState(&m_stateManager));
    m_stateManager.RegisterState(new MovingLeftState(&m_stateManager));
    m_stateManager.RegisterState(new MovingRightState(&m_stateManager));

    m_isRunning = true;
    return true;
}

std::string GameLoop::GetCurrWorkingDir() const
{
#ifdef __linux__
    static constexpr size_t PATH_MAX{512};
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr)
    {
        return cwd;
    }
    else
    {
        return "getcwd() error";
    }
#endif
    return "I don't know, why you asking me.";
}

void GameLoop::CheckPos(float deltaTime)
{
    // by X
    //bool isUpdateX = false;
   // if (m_textureRect.x <= (m_nWindowWidth - m_textureRect.w) && m_hasNotReachedEndX)
   // {
        m_stateManager.ChangeState(EState::eMovingRightState);
    //    isUpdateX = true;
   // }
    //else if (m_textureRect.x <= 0 && !m_hasNotReachedEndX)
   // {
    //    m_hasNotReachedEndX = true;
        // m_textureRect.x += static_cast<int>(m_ProjectileVelocity.y * deltaTime);
        m_stateManager.ChangeState(EState::eMovingRightState);
    //    isUpdateX = true;
   // }
   // else
   // {
//        m_hasNotReachedEndX = false;
        m_stateManager.ChangeState(EState::eMovingLeftState);
    //    isUpdateX = true;
   // }

  //  if (isUpdateX)
        m_stateManager.Update(deltaTime);

    // m_textureRect.y Projectile's X and Y
   // bool isUpdateY = false;
   // if (m_textureRect.y <= (m_nWindowHeight - m_textureRect.h) && m_hasNotReachedEndY)
   //{
        m_stateManager.ChangeState(EState::eMovingDownState);
   //     isUpdateY = true;
   // }
    //else if (m_textureRect.y <= 0 && !m_hasNotReachedEndY)
   // {
    //    m_hasNotReachedEndY = true;
        // m_textureRect.y += static_cast<int>(m_fProjectileVelY * deltaTime);
        m_stateManager.ChangeState(EState::eMovingDownState);
   //     isUpdateY = true;
    //}
    //else
    //{
    //    m_hasNotReachedEndY = false;
        m_stateManager.ChangeState(EState::eMovingUpState);
    //    isUpdateY = true;
   // }

    //if (isUpdateY)
        m_stateManager.Update(deltaTime);
}

void GameLoop::ProcessInput()
{
    // SDL_Event event;

    if (SDL_PollEvent(&m_event) != 0)
    {
        switch (m_event.type)
        {
        case SDL_QUIT:
        {
            std::cout << "SDL QUIT\n";
            m_isRunning = false;
            break;
        }
        case SDL_KEYDOWN:
        {
            std::cout << "Button pressed - ";
            switch (m_event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
            {
                m_isRunning = false;
                break;
            }
            case SDLK_a:
            {
                std::cout << "a\n";
                SharedData::Get().TimerStart(2);
                break;
            }
            case SDLK_s:
            {
                std::cout << "s\n";
                SharedData::Get().TimerStop();
                break;
            }
            case SDLK_0:
            {
                std::cout << "0\n";
                SharedData::Get().SetOnTick([](double dElapsedTime) {
                    std::cout << "MainLoop::Elapsed time: " << dElapsedTime << "\n";
                });
                break;
            }
            case SDLK_1:
            {
                std::cout << "1\n";
                SharedData::Get().SetOnTick([this](double dElapsedTime) {
                    std::cout << "lambda\n";
                    m_textureRect.w += 2 * dElapsedTime * 0.5;
                    m_textureRect.h += 2 * dElapsedTime * 0.5;
                });

                break;
            }
            case SDLK_2:
            {
                std::cout << "2\n";
                break;
            }
            default:
                break;
            }

            break;
        }
        default:
            break;
        }
    }
}

void GameLoop::Update()
{
    // wait until 16ms has passed since last frame
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_nTicksLastFrame + m_FRAME_TARGET_TIME))
        ;

    // The Delta time is the difference between in ticks from last frame converted to
    // seconds
    float deltaTime = (SDL_GetTicks() - m_nTicksLastFrame) / 1000.0f;

    // Clamp Delta time to a maximum value
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    m_nTicksLastFrame = SDL_GetTicks();

    // auto FPS = 1/deltaTime;

    // std::cout << "FPS: " << FPS << ", deltaTime: " << deltaTime << "\n";

    CheckPos(deltaTime);
}

void GameLoop::Render()
{
    SDL_SetRenderDrawColor(m_renderer, 255, 21, 21, 255);
    SDL_RenderClear(m_renderer);

    SDL_RenderCopy(m_renderer, m_image, nullptr, &m_textureRect);

    SDL_RenderPresent(m_renderer);
}

void GameLoop::Destroy()
{
    SDL_DestroyTexture(m_image);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
