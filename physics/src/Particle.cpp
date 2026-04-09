#include "../include/Particle.h"
#include "../include/Constants.h"
#include "../../graphics/include/Circle.h"
#include "../../utils/include/Utils.h"

Utils utils;

Particle::Particle(int pos_x, int pos_y, int radius, SDL_Color color)
    : pos(pos_x, pos_y), radius(radius), color(color) {

    this->velocity.setX(utils.generateRandomNumber(-5, 5));
    this->velocity.setY(utils.generateRandomNumber(-5, 5));

    this->acceleration.setX(0);
    this->acceleration.setY(0);
}

void Particle::drawParticle(SDL_Renderer* renderer) const {
    Circle circle(renderer, (int)this->pos.getX(), (int)this->pos.getY(), this->radius, this->color);
}

void Particle::updateState(double dt) {

    this->acceleration.setY(Constants::GRAVITY);

    this->velocity = this->velocity + this->acceleration * dt;

    this->pos = this->pos + this->velocity * dt;

    this->acceleration.setX(0);
    this->acceleration.setY(0);


}

void Particle::checkEdges(double width, double height) {
    double x = pos.getX();
    double y = pos.getY();

    if (x - this->radius < 0) {
        this->pos.setX(this->radius);
        this->velocity.setX(this->velocity.getX() * -0.8);
    } else if (x + this->radius > width) {
        this->pos.setX(width - this->radius);
        this->velocity.setX(this->velocity.getX() * -0.8);
    }

    // Colisão com topo e fundo (Eixo Y)
    if (y - this->radius < 0) {
        this->pos.setY(this->radius);
        this->velocity.setY(this->velocity.getY() * -0.8);
    } else if (y + this->radius > height) {
        this->pos.setY(height - this->radius);
        this->velocity.setY(this->velocity.getY() * -0.8);
    }
}
