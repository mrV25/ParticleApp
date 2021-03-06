#pragma once
#include <SDL.h>
#include "Test.h"
#include "PostProcessor.h"

namespace particle_app {
class Screen {
 public:
  const static int WINDOW_SIZE_X = 800;
  const static int WINDOW_SIZE_Y = 600;
  Screen();
  Screen(PostProcessor* post_processor);
  ~Screen();
  bool Init();
  void SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
  void SetPixel(int x, int y, Uint32 colour);
  void SetPixelByIndex(int index, Uint32 colour);
  void Update();
  void PostProcess();
  void RenderLoop();
  bool Close();

 private:
  SDL_Window* window_;
  SDL_Renderer* renderer_;
  SDL_Texture* texture_;
  Uint32* pixel_data_;
  PostProcessor* post_processor_;
  bool quit_;
};
}  // namespace particle_app
