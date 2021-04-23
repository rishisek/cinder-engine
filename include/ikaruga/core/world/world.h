//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/game_world.h>
#include <ikaruga/core/objects/projectile/projectile.h>
#include <ikaruga/core/objects/enemy/enemy.h>

namespace ikaruga::world {
class World : public game_engine::GameWorld {
 public:
  World();
  const std::vector<objects::projectile::Projectile *> &GetProjectiles() const;
  const std::vector<std::unique_ptr<ikaruga::objects::enemy::Enemy>> &GetEnemies() const;
  void Update() override;
  void AddProjectile(objects::projectile::Projectile *const projectile);
  void World::AddEnemy(std::unique_ptr<ikaruga::objects::enemy::Enemy> &&enemy);
  virtual ~World();
 private:
  std::vector<objects::projectile::Projectile *> projectiles_;
  std::vector<std::unique_ptr<ikaruga::objects::enemy::Enemy>> enemies_;

  void UpdateProjectiles();
  void UpdateEnemies();
};
}