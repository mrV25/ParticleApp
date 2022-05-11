#include "ExplosionScene.h"

namespace particle_app {
ExplosionScene::ExplosionScene(int particle_count, Mover* mover): AnimatedParticlesSwarmScene(particle_count, mover){};
void ExplosionScene::ResetSwarmToCenter() { swarm_->ResetToCenter(); }
void ExplosionScene::GiveSwarmKick(double force) { swarm_->KickAll(force); }
}
