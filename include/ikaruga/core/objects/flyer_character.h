//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/character_object.h>
#include <ikaruga/core/objects/projectile/projectile_type.h>
#include <ikaruga/core/objects/projectile/projectile.h>

namespace ikaruga {
class FlyerCharacter : public game_engine::CharacterObject {
 public:
  FlyerCharacter(const std::vector<ProjectileType> &projectile_types,
                 const glm::vec2 &position,
                 const glm::vec2 &velocity);
  void Update() override;
  Projectile Shoot();
  void ToggleProjectileType();
 private:
  std::vector<ProjectileType> projectile_types_;
  double shoot_angle_radians_ = - M_PI / 2.0;
  size_t current_projectile_type_index_ = 0;
};
}
