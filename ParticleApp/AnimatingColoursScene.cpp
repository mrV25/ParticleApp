#include <iostream>
#include <math.h>
#include <SDL.h>
#include "AnimatingColoursScene.h"
#include "Screen.h"

namespace particle_app {
AnimatingColoursScene::AnimatingColoursScene() {
  std::cout << "AnimatingColours scene created" << std::endl;
}

void AnimatingColoursScene::RenderTick(Screen* screen) {
  int sdl_tick = SDL_GetTicks();
  double gradient_colour_from_tick = abs(sin(sdl_tick * 0.001)) * 255;
  std::cout << "sdl tick: " << sdl_tick << " " << (int)gradient_colour_from_tick << std::endl;

  for (int x = 1; x < Screen::WINDOW_SIZE_X; x++) {
    for (int y = 1; y < Screen::WINDOW_SIZE_Y; y++) {
      screen->SetPixel(x, y, (int)(255 - abs(sin(x * 0.001)) * 255), (int)(abs(sin(y * 0.003))), (int)gradient_colour_from_tick);
    }
  }
}
}
