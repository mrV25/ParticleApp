#include <iostream>
#include "AnimatedParticlesSwarmScene.h"
#include "Screen.h"

namespace particle_app {
  AnimatedParticlesSwarmScene::AnimatedParticlesSwarmScene(int particle_count, Mover* mover): mover_(mover), colourer_(NULL), ParticleSwarmScene(particle_count) {}
  AnimatedParticlesSwarmScene::AnimatedParticlesSwarmScene(int particle_count, Mover* mover, Colourer* colourer): mover_(mover), colourer_(colourer), ParticleSwarmScene(particle_count) {}
  void AnimatedParticlesSwarmScene::RenderTick(Screen* screen, int render_tick_diff) {
    Particle* particles = this->swarm_->particles();
    for (int i = 0; i < this->swarm_->partical_count_; i++) {
      /*
      if (particles[i].x_ < 0) particles[i].x_ = 1;
      if (particles[i].x_ > 1) particles[i].x_ = 0 ;
      if (particles[i].y_ < 0) particles[i].y_ = 1;
      if (particles[i].y_ > 1) particles[i].y_ = 0;
      */

      int calculated_x = (int)(Screen::WINDOW_SIZE_X * particles[i].x_);
      int calculated_y = (int)((Screen::WINDOW_SIZE_X * particles[i].y_) - ((Screen::WINDOW_SIZE_X - Screen::WINDOW_SIZE_Y) /2));

      screen->SetPixel(calculated_x, calculated_y, particles[i].colour_);
      mover_->move(&particles[i], render_tick_diff);

      if (colourer_ != NULL) {
        colourer_->SetColour(&particles[i], tick_);
      }
    }
  }
}
