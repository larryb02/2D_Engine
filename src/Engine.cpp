#include "Engine.hpp"

namespace Engine
{
    SDL_Window *_window;
    SDL_GLContext _context;
    SDL_Event _ev;
    unsigned int _screenHeight, _screenWidth;
    State engineState;

    void Init()
    {

        _window = nullptr;
        _screenHeight = 768;
        _screenWidth = 1366;
        engineState = Game::RUNNING;

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
                engineState = QUIT;
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

}
