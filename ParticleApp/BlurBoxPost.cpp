#include <iostream>
#include "BlurBoxPost.h"
#include "ColourHelper.h"

namespace particle_app {

BlurBoxPost::BlurBoxPost(double blur) : blur_(blur) {}

void BlurBoxPost::Do(Uint32* pixel_data, int screen_size_x, int screen_size_y) {
  Uint32* temp = pixel_data;

  for (int x = 0; x < screen_size_x; x++) {
    for (int y = 0; y < screen_size_y; y++) {
      int total_neighbor_count = 0;
      int total_neighbor_red = 0;
      int total_neighbor_blue = 0;
      int total_neighbor_green = 0;
      for (int border_x = -1; border_x <= 1; border_x++) {
        for (int border_y = -1; border_y <= 1; border_y++) {
          int neighbor_x = x + border_x;
          int neighbor_y = y + border_y;
          if (neighbor_x < 0 || neighbor_y < 0 || neighbor_x >= screen_size_x || neighbor_y >= screen_size_y) {
            continue;
          }
          RGB rgb = ColourHelper::Uint32ToRgb(pixel_data[neighbor_x + neighbor_y * screen_size_x]);
          total_neighbor_red += rgb.red;
          total_neighbor_green += rgb.green;
          total_neighbor_blue += rgb.blue;
          total_neighbor_count++;
        }
      }

      temp[x + y * screen_size_x] =
          ColourHelper::RgbToUint32((int)(total_neighbor_red / total_neighbor_count / blur_),
                                    (int)(total_neighbor_green / total_neighbor_count / blur_),
                                    (int)(total_neighbor_blue / total_neighbor_count / blur_));
    }
  }
  pixel_data = temp;
}
}
