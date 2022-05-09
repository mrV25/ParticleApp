#pragma once
#include "Screen.h"

namespace particle_app {
class Scene {
 public:
  Scene();
  virtual void RenderTick(Screen* screen);
  void RenderOnScreen(Screen* screen);

 protected:
  int tick;
};
}  // namespace particle_app
