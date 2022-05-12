#pragma once
#include "Colourer.h"

namespace particle_app {
class RandGradientColourer : public Colourer {
 public:
  RandGradientColourer();
  RandGradientColourer(int change_speed);
  void SetColour(Particle* particle) override;
  void InitColour(Particle* particle) override;

 protected:
  int change_speed_;
};

}
