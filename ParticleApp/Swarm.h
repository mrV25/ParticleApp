#pragma once
#include "Particle.h"
#include "Mover.h"

namespace particle_app {
class Swarm {
 public:
  Swarm();
  Swarm(int partical_count);
  Swarm(int partical_count, Mover* mover);
  ~Swarm();
  int partical_count_;
  int const static DEFAULT_PARTICAL_COUNT = 10;
  void PrintInfo();
  Particle* const particles() const { return particles_; }
  void set_mover(Mover* mover) { mover_ = mover; }
  void tick();

 private:
  Particle* particles_;
  Mover* mover_;
};
}
