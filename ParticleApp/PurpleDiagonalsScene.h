#pragma once
#include "Screen.h"
#include "Scene.h"

namespace particle_app {
class PurpleDiagonalsScene : public Scene {
 public:
  PurpleDiagonalsScene();
  void RenderTick(Screen* screen) override;

 protected:
  int context_pixel_index_;
  int offset_;

};
}  // namespace particle_app
