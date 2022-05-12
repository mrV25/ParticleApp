#include "ExplosionScene.h"

namespace particle_app {
ExplosionScene::ExplosionScene(int particle_count, Mover* mover): AnimatedParticlesSwarmScene(particle_count, mover){};
ExplosionScene::ExplosionScene(int particle_count, Mover* mover, Colourer* colourer): AnimatedParticlesSwarmScene(particle_count, mover, colourer){};
void ExplosionScene::ResetSwarmToCenter() { swarm_->ResetToCenter(); }
void ExplosionScene::GiveSwarmKick(double force) { swarm_->KickAll(force); }
}
