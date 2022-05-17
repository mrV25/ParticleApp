#include <iostream>
#include "SpiralMover.h"

namespace particle_app {
SpiralMover::SpiralMover(): speed_(1) {};
SpiralMover::SpiralMover(double speed): speed_(speed) {};

void SpiralMover::move(Particle* particle) {
  int ticks = SDL_GetTicks();

  particle->direction_ += 1 * speed_;

  double x_speed = particle->speed_ * cos(particle->direction_);
  double y_speed = particle->speed_ * sin(particle->direction_);

  particle->x_ += x_speed * speed_;
  particle->y_ += y_speed * speed_;

  if (rand() < RAND_MAX / 100) {
    particle->x_ = 0.5;
    particle->y_ = 0.5;
  }
}
}
