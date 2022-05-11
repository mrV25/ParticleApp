#include <iostream>
#include "AnimatedParticlesSwarmScene.h"
#include "Screen.h"

namespace particle_app {
  AnimatedParticlesSwarmScene::AnimatedParticlesSwarmScene(int particle_count, Mover* mover): mover_(mover), ParticleSwarmScene(particle_count) {}
  void AnimatedParticlesSwarmScene::RenderTick(Screen* screen) {
    Particle* particles = this->swarm_->particles();
    for (int i = 0; i < this->swarm_->partical_count_; i++) {
      if (particles[i].x_ < 0) particles[i].x_ = 1;
      if (particles[i].x_ > 1) particles[i].x_ = 0 ;
      if (particles[i].y_ < 0) particles[i].y_ = 1;
      if (particles[i].y_ > 1) particles[i].y_ = 0;

      int calculated_x = (int)(Screen::WINDOW_SIZE_X * particles[i].x_)%Screen::WINDOW_SIZE_X;
      int calculated_y = (int)(Screen::WINDOW_SIZE_Y * particles[i].y_)%Screen::WINDOW_SIZE_Y;




      screen->SetPixel(calculated_x, calculated_y, particles[i].colour_);
      mover_->move(&particles[i]);
    }
  }
}
