//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <ikaruga/core/objects/projectile/projectile.h>

namespace ikaruga {
class World : public game_engine::GameObject {
 public:
  World(game_engine::PhysicsComponent* physics_component);
  const std::vector<Projectile> &GetProjectiles() const;
  void Update(game_engine::GameObject &world) override;
  void AddProjectile(const Projectile &projectile);
 private:
  void UpdateProjectiles();
  std::vector<Projectile> projectiles_;
};
}