//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/world/world.h"

namespace ikaruga {

const std::vector<Projectile> &World::GetProjectiles() const {
  return projectiles_;
}

void World::UpdateProjectiles() {
  for (Projectile &projectile: projectiles_) {
    projectile.Update(*this);
  }
}

void World::Update(game_engine::GameObject &world) {
  UpdateProjectiles();
}

void World::AddProjectile(const Projectile &projectile) {
  projectiles_.push_back(projectile);
}

World::World(game_engine::PhysicsComponent *physics_component)
    : GameObject(physics_component) {}
}