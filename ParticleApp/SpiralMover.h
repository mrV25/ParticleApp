#pragma once
#include "Mover.h"

namespace particle_app {
class SpiralMover : public Mover {
 public:
  SpiralMover();
  SpiralMover(double speed);
  void move(Particle* particle) override;

 protected:
  double speed_;
};
}
