//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <ikaruga/core/objects/projectile/projectile_type.h>
#include <ikaruga/core/objects/enemy/movement/patterns.h>

namespace ikaruga::objects::enemy {
class EnemyType {
 public:
  EnemyType(float max_health,
            ikaruga::objects::enemy::movement::Pattern pattern,
            const std::vector<projectile::ProjectileType> &projectile_types,
            const ci::Color &color);
  float GetMaxHealth() const;
  const std::vector<projectile::ProjectileType> &GetProjectileTypes() const;
  const ci::ColorT<float> &GetColor() const;
 private:
  float max_health_;
  movement::Pattern pattern_;
  std::vector<projectile::ProjectileType> projectile_types_;
  ci::ColorT<float> color_;
};
}