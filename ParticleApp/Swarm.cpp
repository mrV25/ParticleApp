#include <iostream>
#include "Swarm.h"
#include "RandHelper.h"

namespace particle_app {
  Swarm::Swarm(): partical_count_(Swarm::DEFAULT_PARTICAL_COUNT), mover_(NULL) {
    std::cout << "New swarm created for " << Swarm::DEFAULT_PARTICAL_COUNT << " particles" << std::endl;
    particles_ = new Particle[Swarm::DEFAULT_PARTICAL_COUNT];
    partical_count_ = Swarm::DEFAULT_PARTICAL_COUNT;
  }
  Swarm::Swarm(int partical_count): mover_(NULL) {
    std::cout << "New swarm created for " << partical_count << " particles" << std::endl;
    particles_ = new Particle[partical_count];
    partical_count_ = partical_count;
  }
  Swarm::Swarm(int partical_count, Mover* mover): mover_(mover) {
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
  void Swarm::ResetToCenter() {
    for (int i = 0; i < partical_count_; i++) {
      particles_[i].x_ = 0.5;
      particles_[i].y_ = 0.5;
    }
  }
  void Swarm::KickAll(double force) {
    for (int i = 0; i < partical_count_; i++) {
      double direction_angle = RandHelper::randToLimit(2 * M_PI);
      double speed = RandHelper::randToLimit(40);

      double x_speed_part = cos(direction_angle * M_PI / 180.0);
      double y_speed_part = sin(direction_angle * M_PI / 180.0);
      particles_[i].x_speed_ = force * force * force * RandHelper::randSign() * speed * speed * speed * x_speed_part;
      particles_[i].y_speed_ = force * force * force * RandHelper::randSign() * speed * speed * speed * y_speed_part;
      particles_[i].direction_ = direction_angle;
      particles_[i].speed_ = force*speed;
    }
  }
void Swarm::tick() {
  if (mover_ == NULL) {
    return;
  }
  for (int i = 0; i < partical_count_; i++) {
    mover_->move(&particles_[i]);
  }
}

}
