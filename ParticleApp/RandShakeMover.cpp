#include <iostream>
#include <stdlib.h>
#include "RandShakeMover.h"

namespace particle_app {
  void RandShakeMover::move(Particle* particle) {
    shake(&particle->x_, 700);
    shake(&particle->y_, 800);
  }

  void RandShakeMover::shake(double* coord, int strength) {
    *coord += (double)(rand() - RAND_MAX / 2) / RAND_MAX / strength;
    if (*coord < 0) *coord = 0;
  }
}
