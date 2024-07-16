#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <glad/glad.h>

namespace Engine
{

    // state
    enum State { RUNNING, PAUSED, QUIT }; //thinking about moving this to game logic
    enum WindowMode {FULLSCREEN, BORDERLESS, WINDOWED};
    // functions
    void Init();
    void processInput();
    void Render();
    void Update();
    void Quit();
    void Run();
    // void changeViewport(const unsigned int width, const unsigned int height); unnecessary 
    State getState();
    WindowMode getWindowMode();
    unsigned int getScreenWidth();
    unsigned int getScreenHeight();

}

#endif