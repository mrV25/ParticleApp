#include <iostream>
#include "Scene.h"
#include "Screen.h"

namespace particle_app {

Screen::Screen()
    : window_(NULL),
      renderer_(NULL),
      texture_(NULL),
      pixel_data_(NULL),
      quit_(false) {
}

bool Screen::Init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
  std::cout << "Error with SLD" << "\n";
    return false;
  }

  SDL_Window* window =
      SDL_CreateWindow("Particle app", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, Screen::WINDOW_SIZE_X, Screen::WINDOW_SIZE_Y, SDL_WINDOW_SHOWN);

  if (window == NULL) {
    SDL_Quit();
    return 2;
  }

  std::cout << "SLD is fine" << "\n";

  this->renderer_ = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  this->texture_ = SDL_CreateTexture(this->renderer_, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, Screen::WINDOW_SIZE_X, Screen::WINDOW_SIZE_Y); 

  if (this->renderer_ == NULL) {
    SDL_DestroyWindow(window);
    std::cout << "Can not create renderer" << "\n";
  }

  if (this->texture_ == NULL) {
    SDL_DestroyRenderer(this->renderer_);
    SDL_DestroyWindow(window);
    std::cout << "Can not create renderer" << "\n";
  }

  this->pixel_data_ = new Uint32[Screen::WINDOW_SIZE_X*Screen::WINDOW_SIZE_Y];
  memset(this->pixel_data_, 72, Screen::WINDOW_SIZE_X * Screen::WINDOW_SIZE_Y * sizeof(Uint32));

  for (int i=0; i < Screen::WINDOW_SIZE_X * Screen::WINDOW_SIZE_Y; i++) {
    // this->pixel_data_[i] = 0xFF78dF0F;
    this->pixel_data_[i] = 0xFF00D0FF;
  }
  this->Update();
}

void Screen::SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
  Uint32 color = 0;

  color += red;
  color <<= 8;
  color += green;
  color <<= 8;
  color += blue;
  color += 0xFF;

  this->pixel_data_[x + y * Screen::WINDOW_SIZE_Y] = color;
}
void Screen::SetPixelByIndex(int index, Uint32 color) {
  this->pixel_data_[index] = color;
}
void Screen::Update() {
  SDL_UpdateTexture(this->texture_, NULL, this->pixel_data_, Screen::WINDOW_SIZE_X * sizeof(Uint32));
  SDL_RenderClear(this->renderer_);
  SDL_RenderCopy(this->renderer_, this->texture_, NULL, NULL);
  SDL_RenderPresent(this->renderer_);
}
void Screen::RenderLoop() {
  SDL_Event event;
  int context_pixel_index = 1;
  int offset = 0;
  while (!Screen::quit_) {
    this->SetPixel(2 + offset + context_pixel_index, context_pixel_index, 0, 20, 120);
    int prev_pixel =
        offset + (context_pixel_index - 1) + (context_pixel_index - 1) * Screen::WINDOW_SIZE_X;
    int next_pixel = offset + context_pixel_index + context_pixel_index * Screen::WINDOW_SIZE_X;
    if (next_pixel >= Screen::WINDOW_SIZE_X * Screen::WINDOW_SIZE_Y) {
      context_pixel_index = 1;
      offset += 10;
      continue;
    }
    this->pixel_data_[prev_pixel] = 0x00000000;
    this->pixel_data_[next_pixel] = 0xFFFFFFFF;
    context_pixel_index++;

    this->Update();

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        this->quit_ = true;
      }
    }
  }
}
/*
void Screen::RenderLoop(Scene* scene) {
  SDL_Event event;
  while (!Screen::quit_) {

    scene->RenderTick();

    this->Update();
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        this->quit_ = true;
      }
    }
  }
}
*/
bool Screen::Close() {
  delete[] this->pixel_data_;
  SDL_DestroyTexture(this->texture_);
  SDL_DestroyRenderer(this->renderer_);
  SDL_DestroyWindow(this->window_);
  SDL_Quit();

  return true;
}

}