#pragma once
#include "Scene.h"
#include "Swarm.h"

namespace particle_app {
class ParticleSwarmScene : public Scene {
 public:
  ParticleSwarmScene(int particle_count);
  virtual ~ParticleSwarmScene();
  void RenderTick(Screen* screen) override;

 private:
  Swarm* swarm_;
};
}
