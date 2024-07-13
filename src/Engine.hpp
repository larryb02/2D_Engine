#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <glad/glad.h>

namespace Engine
{

    // state
    enum State { RUNNING, PAUSED, QUIT };
    extern State engineState;
    // functions
    void Init();
    void processInput();
    void Render(); // might remove
    void Update();
    void Quit();
    void Run(); 

}

#endif