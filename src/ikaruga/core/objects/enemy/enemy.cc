//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/enemy/enemy.h"
#include <game_engine/components/physics_component.h>

namespace ikaruga::objects::enemy {
using projectile::ProjectileShooter;
using projectile::ProjectileType;

Enemy::Enemy(game_engine::PhysicsComponent *physics_component,
             const EnemyType &type)
    : ProjectileShooter(type.GetProjectileTypes()),
      game_engine::CharacterObject(physics_component),
      type_(type) {}

void Enemy::Update(game_engine::GameWorld &world) {
  physics_component_->Update();
}

const EnemyType &Enemy::GetType() const {
  return type_;
}
}
