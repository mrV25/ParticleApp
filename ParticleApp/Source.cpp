#include <SDL.h>

#include <iostream>
#include "Screen.h"
#include "Scene.h"
#include "PurpleDiagonalsScene.h"

using namespace particle_app;

// You must include the command line parameters for your main function to be
// recognized by SDL
int main(int argc, char** args) {
  std::cout << "Here is my code"
            << "\n";

  Screen screen;
  // PurpleDiagonalsScene* scene = new PurpleDiagonalsScene();

  if (screen.Init()) {
    screen.RenderLoop();
    screen.Close();
  }

  std::cout << "SLD quit" << "\n";
  return 0;
}