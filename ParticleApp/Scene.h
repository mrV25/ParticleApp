#pragma once
#include "Screen.h"

namespace particle_app {
class Scene {
 public:
  Scene();
  virtual void RenderTick(Screen* screen);
  void RenderOnScreen(Screen* screen);
};
}  // namespace particle_app
