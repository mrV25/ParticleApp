#pragma once
#include "PostProcessor.h"

namespace particle_app {
class FadePost : public PostProcessor {
 public:
  FadePost(int fade_speed);
  void Do(Uint32* pixel_data, int screen_size_x, int screen_size_y) override;

 protected:
  int fade_speed_;
};
}
