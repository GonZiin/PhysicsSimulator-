//
// Created by Gomes on 09/04/2026.
//

#ifndef PHYSICSSIMULATION_PARTICLE_H
#define PHYSICSSIMULATION_PARTICLE_H

#include <SDL.h>

#include "../../utils/include/Vector2.h"

class Particle {
public:
    Particle(int pos_x, int pos_y, int radius, SDL_Color color);
    void drawParticle(SDL_Renderer* renderer) const;
    void updateState(double dt);
    void checkEdges(double width, double height);
private:
    Vector2<double> pos;
    int radius{};
    Vector2<double> velocity{0.0, 0.0};
    Vector2<double> acceleration{0.0, 0.0};
    SDL_Color color{};
};

#endif //PHYSICSSIMULATION_PARTICLE_H
