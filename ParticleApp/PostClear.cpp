#include <iostream>
#include "PostClear.h"

namespace particle_app {
PostClear::PostClear() {}
void PostClear::Do(Uint32* pixel_data, int screen_size_x, int screen_size_y) {
  memset(pixel_data, 0, screen_size_x * screen_size_y * sizeof(Uint32));
}
}