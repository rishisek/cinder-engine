//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/enemy/enemy.h"
#include "ikaruga/core/objects/enemy/enemy_type.h"

namespace ikaruga {
Enemy::Enemy(const EnemyType &enemy_type) {
  max_health_ = enemy_type.GetMaxHealth();
}

void Enemy::Update() {
  UpdatePosition();
}
}
