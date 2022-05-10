#pragma once
#include "Particle.h"

namespace particle_app {
class Mover {
 public:
  Mover();
  virtual void move(Particle* particle);
};
}
