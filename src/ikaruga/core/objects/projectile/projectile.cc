//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/projectile/projectile.h"

namespace ikaruga {
Projectile::Projectile(ProjectileType type,
                       glm::vec2 position,
                       glm::vec2 velocity)
    : type_(type), GameObject(position, velocity) {}

void Projectile::Update() {
  UpdatePosition();
}

const ProjectileType &Projectile::GetType() const {
  return type_;
}
}