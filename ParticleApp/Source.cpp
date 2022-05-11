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
#include "ExplosionScene.h"
#include "ConstantSpeedMover.h"

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
  AnimatedParticlesSwarmScene animatedSwarmScene(1000, mover);

  ConstantSpeedMover* constantSpeedMover = new ConstantSpeedMover;
  ExplosionScene explosionScene(1000, constantSpeedMover);
  explosionScene.ResetSwarmToCenter();
  explosionScene.GiveSwarmKick(0.001);

  if (screen->Init()) {
    // screen->RenderLoop();
    // purpleScene.RenderOnScreen(screen);
    // coloursScene.RenderOnScreen(screen);
    // swarmScene.RenderOnScreen(screen);
    // animatedSwarmScene.RenderOnScreen(screen);
    explosionScene.RenderOnScreen(screen);
    screen->Close();
  }

  delete mover;
  delete constantSpeedMover;
  delete screen;

  std::cout << "SLD quit" << "\n";
  return 0;
}