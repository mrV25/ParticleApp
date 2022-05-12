#include <iostream>
#include "TimeAwareMover.h"

namespace particle_app {
  TimeAwareMover::TimeAwareMover(int expected_time_per_frame): expected_time_per_frame_(expected_time_per_frame) {}
  void TimeAwareMover::move(Particle* particle, int tick_time_diff) {
    double speed_modifier = tick_time_diff / this->expected_time_per_frame_; 
    // std::cout << tick_time_diff << " " <<  this->expected_time_per_frame_ << " " << speed_modifier << std::endl;

    particle->x_ += particle->x_speed_ * speed_modifier;
    particle->y_ += particle->y_speed_ * speed_modifier;
  }
}
