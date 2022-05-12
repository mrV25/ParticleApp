#pragma once
#include "ParticleSwarmScene.h"
#include "Colourer.h"


namespace particle_app {
class AnimatedParticlesSwarmScene : public ParticleSwarmScene {
 public:
  AnimatedParticlesSwarmScene(int particle_count, Mover* mover);
  AnimatedParticlesSwarmScene(int particle_count, Mover* mover, Colourer* colourer);
  void RenderTick(Screen* screen, int render_tick_diff) override;

 protected:
  Mover* mover_;
  Colourer* colourer_;
};
}
