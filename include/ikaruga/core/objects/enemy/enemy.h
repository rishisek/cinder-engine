//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <ikaruga/core/objects/flyer_character.h>
#include "enemy_type.h"

namespace ikaruga {
class Enemy : public FlyerCharacter {
 public:
  Enemy(const EnemyType &enemy_type,
        const std::vector<ProjectileType> &projectile_types,
        const glm::vec2 &position,
        const glm::vec2 &velocity);
  void Update() override;
 private:
};
}