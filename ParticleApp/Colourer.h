#pragma once
#include "Particle.h"

namespace particle_app {
class Colourer {
 public:
  Colourer();
  virtual void SetColour(Particle* particle);
  virtual void InitColour(Particle* particle);
};
}
