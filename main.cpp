#include <iostream>
#include <SDL.h>

#include "graphics/include/Window.h"
#include "physics/include/Particle.h"

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

    Particle particle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 30, {255, 255, 255, 255});
    bool simulationRunning = true;
    SDL_Event event;

    Uint32 lastTime = SDL_GetTicks();
    while (simulationRunning) {
        Uint32 currentTime = SDL_GetTicks();
        double dt = (currentTime - lastTime) / 1000.0;
        lastTime = currentTime;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                simulationRunning = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        particle.updateState(dt);
        particle.checkEdges(SCREEN_WIDTH, SCREEN_HEIGHT);
        particle.drawParticle(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    window.close();
    return 0;
}