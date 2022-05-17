#include <iostream>
#include "PostProcessor.h"

namespace particle_app {
PostProcessor::PostProcessor() {}
PostProcessor::~PostProcessor() {
  std::cout << "Post processor deleted" << std::endl;
}
void PostProcessor::Do(Uint32* pixel_data, int screen_size_x, int screen_size_y) {
  // TODO: Add your implementation code here.
}
}
