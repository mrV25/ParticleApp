#pragma once
#include <SDL.h>

namespace particle_app {
struct RGB {
  RGB(): red(0), green(0), blue(0){};
  int red;
  int green;
  int blue;
};

class ColourHelper {
 public:
  static Uint32 RgbToUint32(int red, int green, int blue);
  static RGB* Uint32ToRgb(Uint32 colour);
  static Uint32 RandomColour();
  static Uint32 FadeColour(Uint32 colour, int fade_amount);
};
}
