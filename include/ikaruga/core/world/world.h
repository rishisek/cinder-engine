//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <ikaruga/core/objects/projectile/projectile.h>
#include <game_engine/game_world.h>

namespace ikaruga::world {
using objects::projectile::Projectile;
class World : public game_engine::GameWorld {
 public:
  World(game_engine::PhysicsComponent *physics_component);
  const std::vector<Projectile> &GetProjectiles() const;
  void Update() override;
  void AddProjectile(const Projectile &projectile);
 private:
  void UpdateProjectiles();
  std::vector<Projectile> projectiles_;
};
}