#pragma once
#include "Mover.h"

namespace particle_app {
class ConstantSpeedMover : public Mover {
 public:
  ConstantSpeedMover();
  void move(Particle* particle) override;
};
}
