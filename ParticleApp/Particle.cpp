#include <iostream>
#include <stdlib.h>
#include "Particle.h"

namespace particle_app {
Particle::Particle(): colour_(0xFFFFFFFF) {
  x_ = (double)rand() / RAND_MAX;
  y_ = (double)rand() / RAND_MAX;
}
Particle::~Particle() {}
void Particle::printInfo() {
  std::cout << "Particle x: " << x_ << " y: " << y_ << " colour: " << std::hex << colour_ << std::endl;
}
}
