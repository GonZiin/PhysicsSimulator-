#include <iostream>
#include <SDL.h>

#define SCREEN_WIDTH  1920
#define SCREEN_HEIGHT 1080

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    }

    SDL_Window *window = SDL_CreateWindow("PhysicsSimulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "SDL could not create window! SDL Error: "<< SDL_GetError() << std::endl;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cout << "SDL could not create renderer! SDL Error: "<< SDL_GetError() << std::endl;
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

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = nullptr;
    window = nullptr;

    SDL_Quit();
}