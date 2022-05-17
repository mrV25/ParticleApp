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
#include "RandGradientColourer.h"
#include "FadePost.h"
#include "BlurBoxPost.h"
#include "SpiralMover.h"

using namespace particle_app;

// You must include the command line parameters for your main function to be
// recognized by SDL
int main(int argc, char** args) {
  srand(time(NULL));
  std::cout << "Here is my code"
            << "\n";

  // FadePost* post_processor = new FadePost(2);
  BlurBoxPost* post_processor = new BlurBoxPost(1);
  Screen* screen = new Screen(post_processor);

  // Screen* screen = new Screen;

  PurpleDiagonalsScene purpleScene;
  AnimatingColoursScene coloursScene;
  ParticleSwarmScene swarmScene(12);

  // ConstantSpeedMover* mover = new ConstantSpeedMover;
  // TimeAwareMover* mover = new TimeAwareMover(12);
  SpiralMover* mover = new SpiralMover(0.04);
  // RandShakeMover* mover = new RandShakeMover;
  AnimatedParticlesSwarmScene animatedSwarmScene(1000, mover);

  // ExplosionScene explosionScene(1000000, constantSpeedMover);
  // ExplosionScene explosionScene(3000000, timeAwareMover);
  // explosionScene.ResetSwarmToCenter();
  // explosionScene.GiveSwarmKick(0.011);

  SolidColourer* colourer = new SolidColourer(0xFF00FFFF);
  RandGradientColourer* gradientColourer = new RandGradientColourer(2);
  // ColouredExplosionScene colouredExplosionScene(10000, constantSpeedMover, colourer);
  ColouredExplosionScene colouredExplosionScene(1000, mover, gradientColourer);
  colouredExplosionScene.CheckColourer();
  colouredExplosionScene.InitScene();

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
  delete colourer;
  delete gradientColourer;
  delete screen;
  // delete post_processor;

  std::cout << "SLD quit" << "\n";
  return 0;
}