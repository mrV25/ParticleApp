#include "PurpleDiagonalsScene.h"
#include "Screen.h"

namespace particle_app {
PurpleDiagonalsScene::PurpleDiagonalsScene()
    : context_pixel_index_(1), offset_(0){};

void PurpleDiagonalsScene::RenderTick(Screen* screen) {
  int current_x = 2 + this->offset_ + this->context_pixel_index_;
  if (current_x >= Screen::WINDOW_SIZE_X) {
    this->context_pixel_index_ = 1;
    this->offset_ += 10;
    return;
  }

  if (this->context_pixel_index_ >= Screen::WINDOW_SIZE_Y) {
    this->context_pixel_index_ = 1;
    this->offset_ += 12;
    return;
  }

  screen->SetPixel(current_x, this->context_pixel_index_, (this->context_pixel_index_ + this->offset_)%255, 0, 255);
  this->context_pixel_index_++;
};
}

