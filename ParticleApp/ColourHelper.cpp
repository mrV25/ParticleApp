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
RGB* ColourHelper::Uint32ToRgb(Uint32 colour) {
  RGB rgb;
  rgb.blue = (colour >> 0) & 0xFF;
  rgb.green = (colour >> 8) & 0xFF;
  rgb.red = (colour >> 16) & 0xFF;
  return &rgb;
}

Uint32 ColourHelper::RandomColour() {
  return RgbToUint32(
    (int) RandHelper::randToLimit(255),
    (int) RandHelper::randToLimit(255),
    (int) RandHelper::randToLimit(255)
  );
}

Uint32 ColourHelper::FadeColour(Uint32 colour, int fade_amount) {
  RGB* colour_rgb = Uint32ToRgb(colour);

  int red = colour_rgb->red - fade_amount > 0 ? colour_rgb->red - fade_amount : 0;
  int green = colour_rgb->green - fade_amount > 0 ? colour_rgb->green - fade_amount : 0;
  int blue = colour_rgb->blue - fade_amount > 0 ? colour_rgb->blue - fade_amount : 0;
  return RgbToUint32(red, green, blue);
}
}
