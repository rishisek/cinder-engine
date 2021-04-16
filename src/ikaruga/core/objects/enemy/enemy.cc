//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/enemy/enemy.h"
#include <game_engine/physics_component.h>

namespace ikaruga {

Enemy::Enemy(game_engine::PhysicsComponent *physics_component,
             const std::vector<ProjectileType> &projectile_types)
    : ProjectileShooter(projectile_types),
      game_engine::CharacterObject(physics_component) {}

void Enemy::Update() {
  physics_component_->Update();
}
}
