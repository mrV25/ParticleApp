#include <iostream>
#include "ConstantSpeedMover.h"

namespace particle_app {
ConstantSpeedMover::ConstantSpeedMover(){}
void ConstantSpeedMover::move(Particle* particle) {
  particle->x_ += particle->x_speed_;
  particle->y_ += particle->y_speed_;
}
}
