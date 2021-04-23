//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/world/world.h"

namespace ikaruga::world {
const std::vector<Projectile *> &World::GetProjectiles() const {
  return projectiles_;
}

void World::UpdateProjectiles() {
  for (Projectile *projectile: projectiles_) {
    projectile->Update(*this);
  }
}

void World::Update() {
  UpdateProjectiles();
}

void World::AddProjectile(Projectile *const projectile) {
  projectiles_.push_back(projectile);
}

World::World() {}
}