//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/projectile/projectile.h"

namespace ikaruga::objects::projectile {
Projectile::Projectile(ProjectileType type,
                       game_engine::PhysicsComponent *physics_component)
    : type_(type), GameObject(physics_component) {}

void Projectile::Update(game_engine::GameWorld &world) {
  GameObject::Update(world);
}

const ProjectileType &Projectile::GetType() const {
  return type_;
}
}