#include <iostream>
#include <SDL.h>
#include "Scene.h"

namespace particle_app {
Scene::Scene() : tick_(0) {
  last_render_tick_ = SDL_GetTicks();
  std::cout << "Scene created." << std::endl;
}
void Scene::RenderTick(Screen* screen) {
  std::cout << "Rendering empty scene" << "\n";
}
void Scene::RenderTick(Screen* screen, int render_tick_diff) {
  std::cout << this->last_render_tick_ << " " << SDL_GetTicks() << " Diff: " << render_tick_diff << std::endl;
  this->RenderTick(screen);
}
void Scene::RenderOnScreen(Screen* screen) {
  SDL_Event event;
  bool quit = false;
  while (!quit) {
    int render_tick_diff = SDL_GetTicks() - this->last_render_tick_;
    this->last_render_tick_ = SDL_GetTicks();
    this->RenderTick(screen, render_tick_diff);
    // TODO Need to figur out when to reset tick back to 0.
    this->tick_++;

    screen->Update();
    screen->Clear();
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        std::cout << "Quit" << std::endl;
        quit = true;
      }
    }

  }
}
}
