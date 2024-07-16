#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
//PROBLY DELETING
class Window
{
    public:
        unsigned int getScreenWidth();
        unsigned int getScreenHeight();
        Window(const char *name, unsigned int width, unsigned int height);
    private:
        SDL_Window *_window;
        unsigned int _screenWidth, _screenHeight;
        const char *name;
        void createWindow();
        void resizeWindow();

};

#endif