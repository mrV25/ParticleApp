#include <iostream>
#include "Swarm.h"

namespace particle_app {
  Swarm::Swarm(): partical_count_(Swarm::DEFAULT_PARTICAL_COUNT) {
    std::cout << "New swarm created for " << Swarm::DEFAULT_PARTICAL_COUNT << " particles" << std::endl;
    particles_ = new Particle[Swarm::DEFAULT_PARTICAL_COUNT];
    partical_count_ = Swarm::DEFAULT_PARTICAL_COUNT;
  }
  Swarm::Swarm(int partical_count) {
    std::cout << "New swarm created for " << partical_count << " particles" << std::endl;
    particles_ = new Particle[partical_count];
    partical_count_ = partical_count;
  }
  Swarm::~Swarm() { 
    delete[] particles_; 
    std::cout << "Swarm deleted" << std::endl;
  }
  void Swarm::PrintInfo() {
    std::cout << "Swarm info: " << std::endl;
    for (int i = 0; i < partical_count_; i++) {
      particles_[i].printInfo();
    }
  }

}
