//
// Created by rishi on 16-04-2021.
//

#include <vector>
#include "ikaruga/core/objects/enemy/enemy_type.h"

namespace ikaruga::objects::enemy {
float EnemyType::GetMaxHealth() const {
  return max_health_;
}

const std::vector<projectile::ProjectileType> &EnemyType::GetProjectileTypes() const {
  return projectile_types_;
}

EnemyType::EnemyType(float max_health,
                     ikaruga::objects::enemy::movement::Pattern pattern,
                     const std::vector<projectile::ProjectileType> &projectile_types,
                     const ci::Color &color)
    : max_health_(max_health),
      pattern_(pattern),
      projectile_types_(projectile_types),
      color_(color) {}

const ci::ColorT<float> &EnemyType::GetColor() const {
  return color_;
}
}