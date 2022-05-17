#include "PostFade.h"
#include "ColourHelper.h"

namespace particle_app {
PostFade::PostFade(int fade_speed): fade_speed_(fade_speed) {}
void PostFade::Do(Uint32* pixel_data, int screen_size_x, int screen_size_y) {
  for (int x = 0; x < screen_size_x; x++) {
    for (int y = 0; y < screen_size_y; y++) {
      if (pixel_data[x + y * screen_size_x] != 0) {
        pixel_data[x + y * screen_size_x] = ColourHelper::FadeColour(pixel_data[x + y * screen_size_x], this->fade_speed_); 
      }
    }
  }
}
}
