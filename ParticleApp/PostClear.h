#include "PostProcessor.h"

namespace particle_app {
class PostClear: public PostProcessor {
 public:
  PostClear();
  void Do(Uint32* pixel_data, int screen_size_x, int screen_size_y) override;
};
}