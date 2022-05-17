#pragma once
#include "Colourer.h"

namespace particle_app {
class SolidGradientColourer : public Colourer {
 public:
  SolidGradientColourer();
  SolidGradientColourer(double change_speed);
  void SetColour(Particle* particle, int tick) override;
  int CalculateColour(int tick, double change_speed, int offset);

 protected:
  double change_speed_;
  double red_change_rand_;
  double green_change_rand_;
  double blue_change_rand_;
  int red_offset_rand_;
  int green_offset_rand_;
  int blue_offset_rand_;
};
}
