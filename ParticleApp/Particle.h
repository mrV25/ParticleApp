#include <SDL.h>
#pragma once

namespace particle_app {
class Particle {
 public:
  Particle();
  ~Particle();
  void printInfo();
  double x_;
  double y_;
  Uint32 colour_;
};
}
