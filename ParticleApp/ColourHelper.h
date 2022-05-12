#pragma once
#include <SDL.h>

namespace particle_app {
class ColourHelper {
 public:
  static Uint32 RgbToUint32(int red, int green, int blue);
  static Uint32 RandomColour();
};
}
