#pragma once
#include "Screen.h"

namespace particle_app {
class Scene {
 public:
  Scene();
  virtual void RenderTick(Screen* screen);
  virtual void RenderTick(Screen* screen, int render_tick_diff);
  virtual void InitScene();
  void RenderOnScreen(Screen* screen);

 protected:
  int tick_;
  int last_render_tick_;
};
}  // namespace particle_app
