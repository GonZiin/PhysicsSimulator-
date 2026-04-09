#ifndef PHYSICSSIMULATION_CIRCLE_H
#define PHYSICSSIMULATION_CIRCLE_H

#include <SDL.h>

class Circle {
public:
    Circle(SDL_Renderer* renderer, int xc, int yc, int r, SDL_Color color, bool filled = true);

private:
    void CreateCircle(SDL_Renderer* renderer, int xc, int yc, int r, SDL_Color color, bool filled);
    void DrawFilledCircle(SDL_Renderer* renderer, int xc, int yc, int x, int y);
    void DrawCircle(SDL_Renderer* renderer, int xc, int yc, int x, int y);
};

#endif