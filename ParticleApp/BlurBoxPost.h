#pragma once
#include "PostProcessor.h"

namespace particle_app {
class BlurBoxPost : public PostProcessor {
 public:
  BlurBoxPost(double blur);
  void Do(Uint32* pixel_data, int screen_size_x, int screen_size_y) override;

 protected:
  double blur_;
};

}
