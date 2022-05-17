#include "PostProcessor.h"

namespace particle_app {
class ClearPost: public PostProcessor {
 public:
  ClearPost();
  void Do(Uint32* pixel_data, int screen_size_x, int screen_size_y) override;
};
}