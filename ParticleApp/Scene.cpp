#include <iostream>
#include "Scene.h"

namespace particle_app {
Scene::Scene() {
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
