#pragma once
#include "Scene.h"

namespace particle_app {
class AnimatingColoursScene : public Scene {
 public:
  AnimatingColoursScene();
  void RenderTick(Screen* screen) override;
};

}
