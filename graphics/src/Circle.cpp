//
// Created by Gomes on 09/04/2026.
//

#include "../include/Circle.h"

Circle::Circle(SDL_Renderer* renderer, int xc, int yc, int r, SDL_Color color, bool filled) {
    CreateCircle(renderer, xc, yc, r, color, filled);
}

void Circle::CreateCircle(SDL_Renderer* renderer, int xc, int yc, int r, SDL_Color color, bool filled) {
    if (r <= 0) return;

    Uint8 prevR, prevG, prevB, prevA;
    SDL_GetRenderDrawColor(renderer, &prevR, &prevG, &prevB, &prevA);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    auto draw = [&]() {
        if (filled)
            DrawFilledCircle(renderer, xc, yc, x, y);
        else
            DrawCircle(renderer, xc, yc, x, y);
    };

    draw();
    while (y >= x) {
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }

        x++;
        draw();
    }

    SDL_SetRenderDrawColor(renderer, prevR, prevG, prevB, prevA);
}

void Circle::DrawFilledCircle(SDL_Renderer* renderer, int xc, int yc, int x, int y) {
    SDL_RenderDrawLine(renderer, xc - x, yc + y, xc + x, yc + y);
    SDL_RenderDrawLine(renderer, xc - x, yc - y, xc + x, yc - y);
    SDL_RenderDrawLine(renderer, xc - y, yc + x, xc + y, yc + x);
    SDL_RenderDrawLine(renderer, xc - y, yc - x, xc + y, yc - x);
}

void Circle::DrawCircle(SDL_Renderer* renderer, int xc, int yc, int x, int y) {
    SDL_RenderDrawPoint(renderer, xc + x, yc + y);
    SDL_RenderDrawPoint(renderer, xc - x, yc + y);
    SDL_RenderDrawPoint(renderer, xc + x, yc - y);
    SDL_RenderDrawPoint(renderer, xc - x, yc - y);
    SDL_RenderDrawPoint(renderer, xc + y, yc + x);
    SDL_RenderDrawPoint(renderer, xc - y, yc + x);
    SDL_RenderDrawPoint(renderer, xc + y, yc - x);
    SDL_RenderDrawPoint(renderer, xc - y, yc - x);
}