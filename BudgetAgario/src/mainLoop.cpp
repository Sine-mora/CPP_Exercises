#include "mainLoop.h"

#ifdef __linux__
#include <unistd.h>
#elif _WIN32
// windows code goes here
#else

#endif

GameLoop::GameLoop()
    : m_stateManagerForX{},m_stateManagerForY{}, m_window{nullptr}, m_event{}, m_renderer{nullptr},
      m_image{nullptr}, m_textureRect{GetTextureRect()},
      m_ProjectileVelocity{GetProjectileVelocity()},
      m_strImagePath{"../assets/foxy_fox.png"}, m_nTextureWidth{0}, m_nTextureHeight{0},
      m_FPS{60}, m_FRAME_TARGET_TIME{1000 / m_FPS}, m_nTicksLastFrame{0},
      m_hasNotReachedEndX{true}, m_hasNotReachedEndY{true}, m_isRunning{false}, m_yoshi{}
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

    m_stateManagerForX.ChangeState(EState::eGameMenuState);

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
        std::cerr << " image go brrr :P\n";
        return false;
    }

    if (!m_yoshi.Load(m_renderer, "../assets/yoshi.png"))
    {
        std::cerr << " failed to load yoshi :(\n";
        return false;
    }

    m_stateManagerForX.RegisterState(new GameMenuState(&m_stateManagerForX));
    m_stateManagerForX.RegisterState(new MovingLeftState(&m_stateManagerForX));
    m_stateManagerForX.RegisterState(new MovingRightState(&m_stateManagerForX));
    m_stateManagerForX.RegisterState(new CheckPositionStateForX(&m_stateManagerForX));
    m_stateManagerForY.RegisterState(new CheckPositionStateForY(&m_stateManagerForY));
    m_stateManagerForY.RegisterState(new MovingUpState(&m_stateManagerForY));
    m_stateManagerForY.RegisterState(new MovingDownState(&m_stateManagerForY));


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

bool GameLoop::GetUserFunc(Easing::EFunctions& outFunc)
{
    int index = 0;
    std::cout << " enter an easing func: ";
    std::cin >> index;
    static constexpr auto BEGIN{static_cast<int>(Easing::EFunctions::eEaseLinear)};
    static constexpr auto END{static_cast<int>(Easing::EFunctions::eEaseInOutBounce)};
    if (index >= BEGIN && index <= END)
    {
        outFunc = static_cast<Easing::EFunctions>(index);
        return false;
    }
    return true;
}

void GameLoop::CheckPos(float deltaTime)
{
    // By X
    (void) deltaTime;
    m_stateManagerForX.ChangeState(EState::eCheckPositionState);

 // m_stateManagerForX.Update(deltaTime);

    // By Y

    m_stateManagerForY.ChangeState(EState::eCheckPositionState);

  //  m_stateManagerForY.Update(deltaTime);
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
                    m_textureRect.w += static_cast<int>(2 * dElapsedTime * 0.5);
                    m_textureRect.h += static_cast<int>(2 * dElapsedTime * 0.5);
                });

                break;
            }
            case SDLK_2:
            {
                std::cout << "2\n";
                break;
            }
            case SDLK_o:
            {
                SDL_Rect rectStart = m_yoshi.m_destRect;
                const auto& windowSize = SharedData::Get().GetWindowDimensions();
                SDL_Rect rectEnd;
                rectEnd.w = rectStart.w / 2;
                rectEnd.h = rectStart.h / 2;
                rectEnd.x = windowSize.x - rectEnd.w;
                rectEnd.y = windowSize.y - rectEnd.h;
                Easing::EFunctions eFunc{Easing::EFunctions::eEaseLinear};
                while (GetUserFunc(eFunc))
                    ;
                m_yoshi.ResetDestRect();
                m_yoshi.Start(rectStart, rectEnd, 5, eFunc);
                break;
            }
            case SDLK_p:
            {
                const auto& windowSize = SharedData::Get().GetWindowDimensions();
                SDL_Point posStart{windowSize.x - m_yoshi.m_destRect.w,
                                   windowSize.y - m_yoshi.m_destRect.h};
                SDL_Point posEnd{0, 0};
                m_yoshi.Start(posStart, posEnd, 5, Easing::EFunctions::eEaseOutBounce);
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
    float deltaTime = (SDL_GetTicks() - m_nTicksLastFrame) / 1000.0;

    // Clamp Delta time to a maximum value
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    m_nTicksLastFrame = SDL_GetTicks();

    // auto FPS = 1/deltaTime;

    // std::cout << "FPS: " << FPS << ", deltaTime: " << deltaTime << "\n";

    CheckPos(deltaTime);
    m_yoshi.Update(deltaTime);
}

void GameLoop::Render()
{
    SDL_SetRenderDrawColor(m_renderer, 255, 21, 21, 255);
    SDL_RenderClear(m_renderer);

    SDL_RenderCopy(m_renderer, m_image, nullptr, &m_textureRect);
    m_yoshi.Draw(m_renderer);
    SDL_RenderPresent(m_renderer);
}

void GameLoop::Destroy()
{
    SDL_DestroyTexture(m_image);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
