#pragma once
#include <SDL.h>

namespace particle_app {
class PostProcessor {
 public:
  PostProcessor();
  ~PostProcessor();
  virtual void Do(Uint32* pixel_data, int screen_size_x, int screen_size_y);
};
}
