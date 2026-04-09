#include "../include/Window.h"
#include <SDL.h>
#include <iostream>

RenderWindow::RenderWindow(const char *title, int width, int height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "SDL could not create window! SDL Error: "<< SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "SDL could not create renderer! SDL Error: "<< SDL_GetError() << std::endl;
    }
}

SDL_Renderer *RenderWindow::GetRenderer() {
    return renderer;
}

void RenderWindow::close() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    window = nullptr;

    SDL_Quit();
}