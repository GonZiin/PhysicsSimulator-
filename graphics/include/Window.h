#ifndef PHYSICSSIMULATION_WINDOW_H
#define PHYSICSSIMULATION_WINDOW_H

#include <SDL.h>

class RenderWindow {
public:
    RenderWindow(const char* title, int width, int height);
    SDL_Renderer* GetRenderer();
    void close();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif
