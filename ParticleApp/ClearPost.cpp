#include <iostream>
#include "ClearPost.h"

namespace particle_app {
ClearPost::ClearPost() {}
void ClearPost::Do(Uint32* pixel_data, int screen_size_x, int screen_size_y) {
  memset(pixel_data, 0, screen_size_x * screen_size_y * sizeof(Uint32));
}
}