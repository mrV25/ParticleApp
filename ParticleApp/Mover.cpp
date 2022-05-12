#include "Mover.h"
#include "Particle.h"

namespace particle_app {
Mover::Mover(){};
void Mover::move(Particle* particle) {}
void Mover::move(Particle* particle, int tick_time_diff) { move(particle); }
}
