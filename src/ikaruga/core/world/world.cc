//
// Created by rishi on 16-04-2021.
//

#include <ikaruga/core/world/world.h>
#include <game_engine/components/physics_component.h>

namespace ikaruga::world {
using objects::projectile::Projectile;
using ikaruga::objects::enemy::Enemy;

const std::vector<Projectile *> &World::GetProjectiles() const {
  return projectiles_;
}

void World::UpdateProjectiles() {
  for (Projectile *projectile: projectiles_) {
    projectile->Update(*this);
  }
}

void World::UpdateEnemies() {
  for (std::unique_ptr<Enemy> &enemy: enemies_) {
    enemy->Update(*this);
  }
  for (Projectile *projectile: projectiles_) {
    enemies_.erase(std::remove_if(enemies_.begin(),
                                  enemies_.end(),
                                  [&](std::unique_ptr<Enemy> &obj) {
                                    return obj->Collides(projectile);
                                  }),
                   enemies_.end());
  }
}

void World::Update() {
  UpdateProjectiles();
  UpdateEnemies();
}

void World::AddProjectile(Projectile *const projectile) {
  projectiles_.push_back(projectile);
}

void World::AddEnemy(std::unique_ptr<Enemy> &&enemy) {
  enemies_.push_back(std::move(enemy));
}

World::World() {}

World::~World() {}

const std::vector<std::unique_ptr<Enemy>> &World::GetEnemies() const {
  return enemies_;
}
}