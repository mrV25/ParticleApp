#include <SDL.h>

#include <iostream>
#include <stdlib.h>
#include "Screen.h"
#include "Scene.h"
#include "PurpleDiagonalsScene.h"
#include "AnimatingColoursScene.h"
#include "ParticleSwarmScene.h"
#include "AnimatedParticlesSwarmScene.h"
#include "RandShakeMover.h"

using namespace particle_app;

// You must include the command line parameters for your main function to be
// recognized by SDL
int main(int argc, char** args) {
  srand(time(NULL));
  std::cout << "Here is my code"
            << "\n";

  Screen* screen = new Screen;
  PurpleDiagonalsScene purpleScene;
  AnimatingColoursScene coloursScene;
  ParticleSwarmScene swarmScene(12);

  RandShakeMover* mover = new RandShakeMover;
  AnimatedParticlesSwarmScene animatedSwarmScene(10, mover);


  if (screen->Init()) {
    // screen->RenderLoop();
    // purpleScene.RenderOnScreen(screen);
    // coloursScene.RenderOnScreen(screen);
    // swarmScene.RenderOnScreen(screen);
    animatedSwarmScene.RenderOnScreen(screen);
    screen->Close();
  }

  delete mover;
  delete screen;

  std::cout << "SLD quit" << "\n";
  return 0;
}