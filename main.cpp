#include <iostream>
#include <SDL.h>

#include "graphics/include/Window.h"

#define SCREEN_WIDTH  1920
#define SCREEN_HEIGHT 1080

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    }

    RenderWindow window("Physics Simulator", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer* renderer = window.GetRenderer();

    if (renderer == nullptr) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    }

    bool simulationRunning = true;
    SDL_Event event;

    while (simulationRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                simulationRunning = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    window.close();
    return 0;
}