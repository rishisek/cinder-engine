//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/flyer_character.h"

namespace ikaruga {
void FlyerCharacter::Update() {
  UpdatePosition();
}

Projectile FlyerCharacter::Shoot() {
  return Projectile(projectile_types_[current_projectile_type_index_],
                    position_,
                    glm::vec2(0, 1));
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