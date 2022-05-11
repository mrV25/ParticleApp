#include <SDL.h>
#pragma once

namespace particle_app {
class Particle {
 public:
  Particle();
  Particle(double x, double y);
  ~Particle();
  void printInfo();
  double x_;
  double y_;
  double x_speed_;
  double y_speed_;
  Uint32 colour_;
};
}
