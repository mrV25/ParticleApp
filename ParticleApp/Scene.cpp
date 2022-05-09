#include <iostream>
#include "Scene.h"

namespace particle_app {
Scene::Scene() : tick(0) {
  std::cout << "Scene created." << std::endl;
}
void Scene::RenderTick(Screen* screen) {
  std::cout << "Rendering empty scene" << "\n";
}
void Scene::RenderOnScreen(Screen* screen) {
  SDL_Event event;
  bool quit = false;
  while (!quit) {

    this->RenderTick(screen);
    // TODO Need to figur out when to reset tick back to 0.
    this->tick++;

    screen->Update();
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        std::cout << "Quit" << std::endl;
        quit = true;
      }
    }
  }
}
}
