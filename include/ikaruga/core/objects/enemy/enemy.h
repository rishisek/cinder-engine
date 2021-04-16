//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <ikaruga/core/objects/projectile/projectile_shooter.h>
#include "enemy_type.h"

namespace ikaruga {
class Enemy : public ProjectileShooter, public game_engine::CharacterObject {
 public:
  Enemy(game_engine::PhysicsComponent *physics_component,
        const std::vector<ProjectileType> &projectile_types);
  void Update() override;
 private:
};
}