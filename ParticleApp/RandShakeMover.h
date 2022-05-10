#pragma once
#include "Mover.h"

namespace particle_app {
class RandShakeMover : public Mover {
 public:
  void move(Particle* particle) override;
  void shake(double* coord, int strength);
};
}
