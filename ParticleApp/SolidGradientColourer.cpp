#include <iostream>
#include "SolidGradientColourer.h"
#include "ColourHelper.h"
#include "RandHelper.h"

namespace particle_app {
SolidGradientColourer::SolidGradientColourer():
  change_speed_(1),
  red_change_rand_(RandHelper::randToOne()),
  green_change_rand_(RandHelper::randToOne()),
  blue_change_rand_(RandHelper::randToOne()),
  red_offset_rand_(RandHelper::randToLimit(255)),
  green_offset_rand_(RandHelper::randToLimit(255)),
  blue_offset_rand_(RandHelper::randToLimit(255)) {
}
SolidGradientColourer::SolidGradientColourer(double change_speed):
  change_speed_(change_speed),
  red_change_rand_(RandHelper::randToOne()),
  green_change_rand_(RandHelper::randToOne()),
  blue_change_rand_(RandHelper::randToOne()),
  red_offset_rand_(RandHelper::randToLimit(255)),
  green_offset_rand_(RandHelper::randToLimit(255)),
  blue_offset_rand_(RandHelper::randToLimit(255)) {
}
void SolidGradientColourer::SetColour(Particle* particle, int tick) {
  int red = CalculateColour(tick, red_change_rand_, red_offset_rand_);
  int green = CalculateColour(tick, green_change_rand_, green_offset_rand_);
  int blue = CalculateColour(tick, blue_change_rand_, blue_offset_rand_);

  particle->colour_ = ColourHelper::RgbToUint32(
    red,
    green,
    blue 
  );
}
int SolidGradientColourer::CalculateColour(int tick, double change_speed, int offset) {
  double radian = (double)(tick + offset) * change_speed / 10;
  double delta = cos(radian);
  double calculated = abs(cos(radian) * 255);
  return (int)calculated;
}
}
