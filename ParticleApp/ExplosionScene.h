#pragma once
#include "AnimatedParticlesSwarmScene.h"

namespace particle_app {
class ExplosionScene : public AnimatedParticlesSwarmScene {
 public:
  ExplosionScene(int particle_count, Mover* mover);
  void ResetSwarmToCenter();
  void GiveSwarmKick(double force);
};
}
