#include <iostream>
#include <stdlib.h>
#include "Particle.h"

namespace particle_app {
Particle::Particle(): colour_(0xFFFFFFFF), x_speed_(0), y_speed_(0), direction_(0), speed_(0) {
  x_ = (double)rand() / RAND_MAX;
  y_ = (double)rand() / RAND_MAX;
}
Particle::Particle(double x, double y) : x_(x), y_(y), x_speed_(0), y_speed_(0), direction_(0), speed_(0), colour_(0xFFFFFFFF) {}
Particle::~Particle() {}
void Particle::printInfo() {
  std::cout << "Particle x: " << x_ << " y: " << y_ << " colour: " << std::hex << colour_ << std::endl;
}
}
