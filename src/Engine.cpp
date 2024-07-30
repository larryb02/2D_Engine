#include "Engine.hpp"

namespace Engine
{
    SDL_Window *m_window;
    SDL_GLContext m_context;
    SDL_Event m_ev;
    unsigned int m_screenHeight, m_screenWidth;
    State m_engineState;
    SDL_Keycode keydown;
    SDL_Keycode keyup;
    // std::vector<renderData> renderQueue;

    void Init(uint32_t height, uint32_t width, std::string title)
    {

        m_window = nullptr;
        m_screenHeight = 768;
        m_screenWidth = 1366;
        m_engineState = Engine::RUNNING;

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

        if ((m_window = SDL_CreateWindow("VIDEO_GAME",
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         m_screenWidth,
                                         m_screenHeight,
                                         SDL_WINDOW_OPENGL)) == nullptr)
        {
            std::cerr << "Failed to init SDL Window" << SDL_GetError()
                      << std::endl;
            SDL_Quit();
        }

        m_context = SDL_GL_CreateContext(m_window);

        if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
        {
            std::cerr << "Failed to init GLAD" << std::endl;
            exit(EXIT_FAILURE);
        }
        glEnable(GL_DEPTH_TEST);
        glViewport(0, 0, m_screenWidth, m_screenHeight);
    }

    void Update()
    {
        SDL_GL_SwapWindow(m_window);
        SDL_Delay(16);
    }

    void Quit()
    {
        std::cout << "Closing..." << std::endl;
        SDL_GL_DeleteContext(m_context);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

    State getState()
    {
        return m_engineState;
    }
    unsigned int getScreenWidth()
    {
        return m_screenWidth;
    }
    unsigned int getScreenHeight()
    {
        return m_screenHeight;
    }
    void processInput()
    {
        // for now just handle closing window
        while (SDL_PollEvent(&m_ev))
        {
            switch (m_ev.type)
            {
            case SDL_QUIT:
                m_engineState = QUIT;
                break;
            
            default:
                keydown = 0;
                keyup = 0;
                break;
            }
            // std::cout << (int32_t)keydown << " " << "Key Pressed | Code: " << std::endl;
            // std::cout << (int32_t)keyup << " " << "Key Released | Code: " << std::endl;
        }
    }

    SDL_Keycode getKeyDown()
    {
        return keydown;
    }

    SDL_Keycode getKeyUp()
    {
        return keyup;
    }

}
