//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/flyer_character.h"

namespace ikaruga {
void FlyerCharacter::Update() {
  UpdatePosition();
  for (ProjectileType &projectile_type: projectile_types_) {
    projectile_type.DecrementCurrentCooldown();
  }
}

Projectile FlyerCharacter::Shoot() {
  projectile_types_[current_projectile_type_index_].StartCooldown();
  return Projectile(projectile_types_[current_projectile_type_index_],
                    position_,
                    glm::vec2(cos(shoot_angle_radians_), sin(shoot_angle_radians_)));
}

void FlyerCharacter::ToggleProjectileType() {
  current_projectile_type_index_++;
  current_projectile_type_index_ %= projectile_types_.size();
}

FlyerCharacter::FlyerCharacter(const std::vector<ProjectileType> &projectile_types,
                               const glm::vec2 &position,
                               const glm::vec2 &velocity)
    : projectile_types_(projectile_types), CharacterObject(position, velocity) {}
}