#include "Colourer.h"

namespace particle_app {
Colourer::Colourer() {}
void Colourer::SetColour(Particle* particle) {}
void Colourer::SetColour(Particle* particle, int tick) {
  this->SetColour(particle);
}
void Colourer::InitColour(Particle* particle){};
}
