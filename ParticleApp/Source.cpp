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
#include "TimeAwareMover.h"
#include "SolidColourer.h"
#include "ColouredExplosionScene.h"

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
  TimeAwareMover* timeAwareMover = new TimeAwareMover(12);
  // ExplosionScene explosionScene(1000000, constantSpeedMover);
  // ExplosionScene explosionScene(3000000, timeAwareMover);
  // explosionScene.ResetSwarmToCenter();
  // explosionScene.GiveSwarmKick(0.011);

  SolidColourer* colourer = new SolidColourer(0xFFFF0000);
  ColouredExplosionScene colouredExplosionScene(1000, constantSpeedMover, colourer);
  colouredExplosionScene.ResetSwarmToCenter();
  colouredExplosionScene.GiveSwarmKick(0.011);
  colouredExplosionScene.CheckColourer();


  if (screen->Init()) {
    // screen->RenderLoop();
    // purpleScene.RenderOnScreen(screen);
    // coloursScene.RenderOnScreen(screen);
    // swarmScene.RenderOnScreen(screen);
    // animatedSwarmScene.RenderOnScreen(screen);
    // explosionScene.RenderOnScreen(screen);
    colouredExplosionScene.RenderOnScreen(screen);
    screen->Close();
  }

  delete mover;
  delete constantSpeedMover;
  delete timeAwareMover;
  delete colourer;
  delete screen;

  std::cout << "SLD quit" << "\n";
  return 0;
}