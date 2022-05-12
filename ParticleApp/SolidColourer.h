#pragma once
#include "Colourer.h"

namespace particle_app {
class SolidColourer : public Colourer {
 public:
  SolidColourer(Uint32 colour);
  void SetColour(Particle* particle) override;

 protected:
  Uint32 colour_;
};
}
