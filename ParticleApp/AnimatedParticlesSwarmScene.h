#pragma once
#include "ParticleSwarmScene.h"


namespace particle_app {
class AnimatedParticlesSwarmScene : public ParticleSwarmScene {
 public:
  AnimatedParticlesSwarmScene(int particle_count, Mover* mover);
  void RenderTick(Screen* screen) override;

 protected:
  Mover* mover_;
};
}
