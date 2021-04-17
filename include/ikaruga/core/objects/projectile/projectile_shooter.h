//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/objects/character_object.h>
#include <ikaruga/core/objects/projectile/projectile_type.h>
#include <ikaruga/core/objects/projectile/projectile.h>

namespace ikaruga {
class ProjectileShooter {
 public:
  ProjectileShooter(const std::vector<ProjectileType> &projectile_types);
  void UpdateCooldowns();
  Projectile Shoot(game_engine::GameObject const &game_object);
  void ToggleProjectileType();
 protected:
  const double kNormalAngle = -M_PI / 2.0;

  std::vector<ProjectileType> projectile_types_;
  double shoot_angle_radians_ = kNormalAngle;
  size_t current_projectile_type_index_ = 0;
};
}
