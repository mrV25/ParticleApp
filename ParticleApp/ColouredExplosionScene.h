#pragma once
#include "ExplosionScene.h"

namespace particle_app {
class ColouredExplosionScene : public ExplosionScene {
 public:
  ColouredExplosionScene(int particle_count, Mover* mover, Colourer* colourer);
  void CheckColourer();
 protected:
  Colourer* colourer_;
};
}
