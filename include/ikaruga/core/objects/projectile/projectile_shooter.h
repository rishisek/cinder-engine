//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <ikaruga/core/objects/projectile/projectile_type.h>
#include <ikaruga/core/objects/projectile/projectile.h>

namespace ikaruga::objects::projectile {
class ProjectileShooter {
 public:
  ProjectileShooter(const std::vector<ProjectileType> &projectile_types);

  // Update all projectile type cooldowns
  void UpdateCooldowns();

  // TODO: Figure out unique_ptr logic for return
  // Returns pointer to a new Projectile of the active type
  Projectile *Shoot(game_engine::GameObject const &game_object);

  // Shifts to next projectile type, looping around to start.
  void ToggleProjectileType();
 protected:
  const double kNormalAngle = -M_PI / 2.0;

  std::vector<ProjectileType> projectile_types_;
  double shoot_angle_radians_ = kNormalAngle;
  size_t current_projectile_type_index_ = 0;
};
}
