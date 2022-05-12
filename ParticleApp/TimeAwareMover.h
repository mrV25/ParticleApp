#pragma once
#include "Mover.h"

namespace particle_app {
class TimeAwareMover : public Mover {
 public:
  TimeAwareMover(int expected_time_per_frame);
  void move(Particle* particle, int tick_time_diff);
 
 protected:
  int expected_time_per_frame_;
};
}
