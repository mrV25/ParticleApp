#include <iostream>
#include "ColouredExplosionScene.h"

namespace particle_app {
ColouredExplosionScene::ColouredExplosionScene(int particle_count, Mover* mover,
                                               Colourer* colourer)
    : ExplosionScene(particle_count, mover, colourer){};
void ColouredExplosionScene::CheckColourer() {
  if (this->colourer_ != NULL) {
    std::cout << "Have colourer" << std::endl;
    return;
  }
  std::cout << "No colourer" << std::endl;
}
void ColouredExplosionScene::InitScene() {
  this->ResetSwarmToCenter();
  this->GiveSwarmKick(0.011);

  Particle* particles = swarm_->particles();

  for (int i = 0; i < swarm_->partical_count_; i++) {
    colourer_->InitColour(&particles[i]);
  }
}
}
