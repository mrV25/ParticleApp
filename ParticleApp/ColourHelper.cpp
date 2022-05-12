#include "ColourHelper.h"
#include "RandHelper.h"

namespace particle_app {
Uint32 ColourHelper::RgbToUint32(int red, int green, int blue) {
  Uint32 colour = 0;

  colour += 0xFF;
  colour <<= 8;
  colour += blue%255;
  colour <<= 8;
  colour += green%255;
  colour <<= 8;
  colour += red%255;

  return colour;

}

Uint32 ColourHelper::RandomColour() {
  return RgbToUint32(
    RandHelper::randToLimit(255),
    RandHelper::randToLimit(255),
    RandHelper::randToLimit(255)
  );
}
}
