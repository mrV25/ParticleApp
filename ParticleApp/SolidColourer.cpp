#include "SolidColourer.h"

namespace particle_app {
  SolidColourer::SolidColourer(Uint32 colour): colour_(colour){};
  void SolidColourer::SetColour(Particle* particle) {
    particle->colour_ = this->colour_;
  }
}
