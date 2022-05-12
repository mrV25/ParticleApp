#include <iostream>
#include <SDL.h>
#include "RandGradientColourer.h"
#include "ColourHelper.h"

namespace particle_app {
RandGradientColourer::RandGradientColourer(): change_speed_(1) {}
RandGradientColourer::RandGradientColourer(int change_speed): change_speed_(change_speed) {}
void RandGradientColourer::SetColour(Particle* particle) {
  Uint32 initial_colour = particle->colour_;

  int blue = (initial_colour >> 0) & 0xFF;
  int green = (initial_colour >> 8) & 0xFF;
  int red = (initial_colour >> 16) & 0xFF;

  // std::cout << std::hex << "init: " << initial_colour << " r: " << red << " g: " << green << " b: " << blue << std::endl;

  particle->colour_ = ColourHelper::RgbToUint32(
    red + change_speed_,
    green + change_speed_,
    blue + change_speed_
  );
}
void RandGradientColourer::InitColour(Particle* particle) {
  particle->colour_ = ColourHelper::RandomColour();
}
}
