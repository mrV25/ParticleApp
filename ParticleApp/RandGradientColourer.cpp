#include <iostream>
#include <SDL.h>
#include "RandGradientColourer.h"
#include "ColourHelper.h"

namespace particle_app {
RandGradientColourer::RandGradientColourer(): change_speed_(1) {}
RandGradientColourer::RandGradientColourer(int change_speed): change_speed_(change_speed) {}
void RandGradientColourer::SetColour(Particle* particle) {
  Uint32 initial_colour = particle->colour_;

  RGB* rgb = ColourHelper::Uint32ToRgb(initial_colour);
  // std::cout << std::hex << "init: " << initial_colour << " r: " << red << " g: " << green << " b: " << blue << std::endl;

  particle->colour_ = ColourHelper::RgbToUint32(
    rgb->red + change_speed_,
    rgb->green + change_speed_,
    rgb->blue + change_speed_
  );
}
void RandGradientColourer::InitColour(Particle* particle) {
  particle->colour_ = ColourHelper::RandomColour();
}
}
