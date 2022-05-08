#include "PurpleDiagonalsScene.h"
#include "Screen.h"

namespace particle_app {
PurpleDiagonalsScene::PurpleDiagonalsScene()
    : context_pixel_index_(1), offset_(0){};

void PurpleDiagonalsScene::RenderTick(Screen screen){
  screen.SetPixel(2 + this->offset_ + this->context_pixel_index_, this->context_pixel_index_, 0, 20, 120);
  int prev_pixel =
      this->offset_ + (this->context_pixel_index_ - 1) + (this->context_pixel_index_ - 1) * Screen::WINDOW_SIZE_X;
  int next_pixel = this->offset_ + this->context_pixel_index_ + this->context_pixel_index_ * Screen::WINDOW_SIZE_X;
  if (next_pixel >= Screen::WINDOW_SIZE_X * Screen::WINDOW_SIZE_Y) {
    this->context_pixel_index_ = 1;
    this->offset_ += 10;
    return;
  }
  screen.SetPixelByIndex(prev_pixel, 0x00000000);
  screen.SetPixelByIndex(next_pixel, 0xFFFFFFFF);
  this->context_pixel_index_++;
};
}

