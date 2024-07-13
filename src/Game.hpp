#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <glad/glad.h>

namespace Game
{

    // state
    enum State{ RUNNING, PAUSED, QUIT };
    extern State _gState;
    // functions
    void Init();
    void processInput();
    void Render(); // might remove
    void Update();
    void Quit();
    void Run(); 

}

#endif