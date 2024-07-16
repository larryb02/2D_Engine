#include "Engine.hpp"

namespace Engine
{
    SDL_Window *_window;
    SDL_GLContext _context;
    SDL_Event _ev;
    unsigned int _screenHeight, _screenWidth;
    State _engineState;
    // std::vector<renderData> renderQueue;

    void Init()
    {

        _window = nullptr;
        _screenHeight = 600;
        _screenWidth = 800;
        _engineState = Engine::RUNNING;

        std::cout << "Initializing Window..." << std::endl;
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            std::cerr << "Failed to init SDL...\n"
                      << std::endl;
            SDL_Quit();
        }
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        if ((_window = SDL_CreateWindow("VIDEO_GAME",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        _screenWidth,
                                        _screenHeight,
                                        SDL_WINDOW_OPENGL)) == nullptr)
        {
            std::cerr << "Failed to init SDL Window" << SDL_GetError()
                      << std::endl;
            SDL_Quit();
        }

        _context = SDL_GL_CreateContext(_window);

        if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
        {
            std::cerr << "Failed to init GLAD" << std::endl;
            exit(EXIT_FAILURE);
        }
        glEnable(GL_DEPTH_TEST);
        glViewport(0, 0, _screenWidth, _screenHeight);
    }

    void processInput()
    {
        // for now just handle closing window
        while (SDL_PollEvent(&_ev))
        {
            switch (_ev.type)
            {
            case SDL_QUIT:
                _engineState = QUIT;
                break;
            case SDL_KEYDOWN:
                if (_ev.key.keysym.sym == SDLK_w)
                if (_ev.key.keysym.sym == SDLK_a)
                if (_ev.key.keysym.sym == SDLK_s)
                if (_ev.key.keysym.sym == SDLK_d)
                    
                // std::cout << kc << std::endl;
                break;
            default:
                break;
            }
        }
    }

    void Update()
    {
        SDL_GL_SwapWindow(_window);
        SDL_Delay(16);
    }

    void Quit()
    {
        std::cout << "Closing..." << std::endl;
        SDL_GL_DeleteContext(_context);
        SDL_DestroyWindow(_window);
        SDL_Quit();
    }

    State getState()
    {
        return _engineState;
    }
    unsigned int getScreenWidth()
    {
        return _screenWidth;
    }
    unsigned int getScreenHeight()
    {
        return _screenHeight;
    }

}
