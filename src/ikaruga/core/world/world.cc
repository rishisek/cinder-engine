//
// Created by rishi on 16-04-2021.
//

#include <ikaruga/core/world/world.h>
#include <game_engine/components/physics_component.h>

namespace ikaruga::world {
using objects::projectile::Projectile;
using ikaruga::objects::enemy::Enemy;

const std::vector<std::unique_ptr<Projectile>> &World::GetProjectiles() const {
  return projectiles_;
}

void World::UpdateProjectiles() {
  for (std::unique_ptr<Projectile> &projectile: projectiles_) {
    projectile->Update(*this);
  }
}

void World::UpdateEnemies() {
  for (std::unique_ptr<Enemy> &enemy: enemies_) {
    enemy->Update(*this);
  }
  for (std::unique_ptr<Projectile> &projectile: projectiles_) {
    enemies_.erase(std::remove_if(enemies_.begin(),
                                  enemies_.end(),
                                  [&](std::unique_ptr<Enemy> &obj) {
                                    return obj->Collides(projectile.get());
                                  }),
                   enemies_.end());
  }
}

void World::Update() {
  UpdateProjectiles();
  UpdateEnemies();
}

void World::AddProjectile(std::unique_ptr<Projectile> &&projectile) {
  projectiles_.push_back(std::move(projectile));
}

void World::AddEnemy(std::unique_ptr<Enemy> &&enemy) {
  enemies_.push_back(std::move(enemy));
}

World::World() {}

World::~World() {}

const std::vector<std::unique_ptr<Enemy>> &World::GetEnemies() const {
  return enemies_;
}

void World::AddProjectile(Projectile *const projectile) {
  // Move ownership to a new std::unique_ptr that can be added to world.
  std::unique_ptr<Projectile> ptr;
  ptr.reset(projectile);
  // std::move required for R-value form of argument. 
  AddProjectile(std::move(ptr));
}
}