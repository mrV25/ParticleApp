#include <iostream>
#include "ParticleSwarmScene.h"
#include "Screen.h"
#include "Particle.h"

namespace particle_app {
ParticleSwarmScene::ParticleSwarmScene(int partical_count) {
  std::cout << "New Particle Swarm Scene created" << std::endl;
  swarm_ = new Swarm(partical_count);
  swarm_->PrintInfo();
}

void ParticleSwarmScene::RenderTick(Screen* screen) {
  Particle* particles = this->swarm_->particles();
  for (int i = 0; i < this->swarm_->partical_count_; i++) {
    screen->SetPixel((int)(Screen::WINDOW_SIZE_X * particles[i].x_),
                     (int)(Screen::WINDOW_SIZE_Y * particles[i].y_), particles[i].colour_);
  }
}
ParticleSwarmScene::~ParticleSwarmScene() { 
  delete swarm_;
  
  std::cout << "Particle swarm scene destroyed" << std::endl;


  
}
}
