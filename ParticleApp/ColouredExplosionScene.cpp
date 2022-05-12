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
}
