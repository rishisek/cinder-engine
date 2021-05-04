//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <ikaruga/core/objects/projectile/projectile_type.h>
#include <ikaruga/core/objects/projectile/projectile.h>
#include <game_engine/objects/character_object.h>

namespace ikaruga::objects::projectile {
class ProjectileShooter : public game_engine::CharacterObject {
 public:
  ProjectileShooter(game_engine::PhysicsComponent *physics_component,
                    const std::vector<ProjectileType> &projectile_types,
                    const glm::vec2 &projectile_spawn_offset);

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
  std::vector<int> cooldowns_;
  double shoot_angle_radians_ = kNormalAngle;
  glm::vec2 projectile_spawn_offset_;
  size_t current_projectile_type_index_ = 0;
};
}
