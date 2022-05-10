#pragma once
#include "Particle.h"

namespace particle_app {
class Swarm {
 public:
  Swarm();
  Swarm(int partical_count);
  ~Swarm();
  int partical_count_;
  int const static DEFAULT_PARTICAL_COUNT = 10;
  void PrintInfo();
  Particle* const particles() const { return particles_; }

 private:
  Particle* particles_;
};
}
