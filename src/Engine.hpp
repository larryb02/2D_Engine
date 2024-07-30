#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <glad/glad.h>

namespace Engine
{

    // state
    enum State { RUNNING, QUIT };
    enum WindowMode { FULLSCREEN, BORDERLESS, WINDOWED };
    // functions
    void Init(uint32_t height, uint32_t width, std::string title);
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
    SDL_Window *getWindowPointer(); //probly change to window pointer
    SDL_Event *getEventPointer(); //probly change to window pointer
    SDL_Keycode getKeyDown();
    SDL_Keycode getKeyUp();
    

}

#endif