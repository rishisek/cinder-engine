//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/enemy/enemy.h"
#include "ikaruga/core/objects/enemy/enemy_type.h"

namespace ikaruga {
Enemy::Enemy(const EnemyType &enemy_type,
             const std::vector<ProjectileType> &projectile_types,
             const glm::vec2 &position,
             const glm::vec2 &velocity) 
             : FlyerCharacter(projectile_types, position, velocity){
  max_health_ = enemy_type.GetMaxHealth();
}

void Enemy::Update() {
  UpdatePosition();
}
}
