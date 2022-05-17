#include <iostream>
#include <iomanip>
#include "Scene.h"
#include "Screen.h"
#include "PostClear.h"

namespace particle_app {

Screen::Screen()
    : window_(NULL),
      renderer_(NULL),
      texture_(NULL),
      pixel_data_(NULL),
      quit_(false),
      post_processor_(new PostClear) {}

Screen::Screen(PostProcessor* post_processor)
    : window_(NULL),
      renderer_(NULL),
      texture_(NULL),
      pixel_data_(NULL),
      quit_(false),
      post_processor_(post_processor) {}

Screen::~Screen() {
  std::cout << "Screen is deleted" << std::endl;
}

bool Screen::Init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
  std::cout << "Error with SLD" << "\n";
    return false;
  }

  this->window_ =
      SDL_CreateWindow("Particle app", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, Screen::WINDOW_SIZE_X, Screen::WINDOW_SIZE_Y, SDL_WINDOW_SHOWN);

  if (this->window_ == NULL) {
    SDL_Quit();
    return false;
  }

  std::cout << "SLD is fine" << "\n";

  this->renderer_ = SDL_CreateRenderer(this->window_, -1, SDL_RENDERER_PRESENTVSYNC);
  this->texture_ = SDL_CreateTexture(this->renderer_, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STATIC, Screen::WINDOW_SIZE_X, Screen::WINDOW_SIZE_Y); 

  if (this->renderer_ == NULL) {
    SDL_DestroyWindow(this->window_);
    std::cout << "Can not create renderer" << "\n";
  }

  if (this->texture_ == NULL) {
    SDL_DestroyRenderer(this->renderer_);
    SDL_DestroyWindow(this->window_);
    std::cout << "Can not create renderer" << "\n";
  }

  this->pixel_data_ = new Uint32[Screen::WINDOW_SIZE_X*Screen::WINDOW_SIZE_Y];
  memset(this->pixel_data_, 0, Screen::WINDOW_SIZE_X * Screen::WINDOW_SIZE_Y * sizeof(Uint32));

  for (int i=0; i < Screen::WINDOW_SIZE_X * Screen::WINDOW_SIZE_Y; i++) {
    // this->pixel_data_[i] = 0xFF78dF0F;
  }
  this->Update();

  return true;
}

void Screen::SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
  Uint32 colour = 0;

  colour += 0xFF;
  colour <<= 8;
  colour += blue;
  colour <<= 8;
  colour += green;
  colour <<= 8;
  colour += red;

  this->pixel_data_[x + y * Screen::WINDOW_SIZE_X] = colour;
}
void Screen::SetPixel(int x, int y, Uint32 colour) {
  if (x >= Screen::WINDOW_SIZE_X || x < 0 || y >= Screen::WINDOW_SIZE_Y || y < 0) {
    return;
  }
  this->pixel_data_[x + y * Screen::WINDOW_SIZE_X] = colour;
}

void Screen::SetPixelByIndex(int index, Uint32 colour) {
  this->pixel_data_[index] = colour;
}
void Screen::Update() {
  SDL_UpdateTexture(this->texture_, NULL, this->pixel_data_, Screen::WINDOW_SIZE_X * sizeof(Uint32));
  SDL_RenderClear(this->renderer_);
  SDL_RenderCopy(this->renderer_, this->texture_, NULL, NULL);
  SDL_RenderPresent(this->renderer_);
}
void Screen::PostProcess() {
  this->post_processor_->Do(this->pixel_data_, Screen::WINDOW_SIZE_X, Screen::WINDOW_SIZE_Y);
}
void Screen::RenderLoop() {
  SDL_Event event;
  int context_pixel_index = 1;
  int offset = 0;
  while (!this->quit_) {
    // this->SetPixel(2 + offset + context_pixel_index, context_pixel_index, 12, 14, 201);
    this->SetPixel(context_pixel_index, context_pixel_index, 255, 0, 0);
    int prev_pixel =
        offset + (context_pixel_index - 1) + (context_pixel_index - 1) * Screen::WINDOW_SIZE_X;
    int next_pixel = offset + context_pixel_index + context_pixel_index * Screen::WINDOW_SIZE_X;
    if (next_pixel >= Screen::WINDOW_SIZE_X * Screen::WINDOW_SIZE_Y) {
      context_pixel_index = 1;
      offset += 10;
      continue;
    }
    // this->pixel_data_[prev_pixel] = 0x00000000;
    // this->pixel_data_[next_pixel] = 0xFFFFFFFF;
    context_pixel_index++;

    this->Update();

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        this->quit_ = true;
      }
    }
  }
}
bool Screen::Close() {
  delete[] this->pixel_data_;
  delete this->post_processor_;
  SDL_DestroyTexture(this->texture_);
  SDL_DestroyRenderer(this->renderer_);
  SDL_DestroyWindow(this->window_);
  SDL_Quit();

  return true;
}
}
