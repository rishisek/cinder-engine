//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/projectile/projectile.h"

namespace ikaruga::objects::projectile {
Projectile::Projectile(ProjectileType type,
                       game_engine::PhysicsComponent *physics_component)
    : GameObject(physics_component), type_(type) {}

void Projectile::Update(game_engine::GameWorld &world) {
  GameObject::Update(world);
}

const ProjectileType &Projectile::GetType() const {
  return type_;
}

void Projectile::Serialize(nlohmann::json &json) const {
//  GameObject::Serialize(json);
}

void Projectile::Deserialize(const nlohmann::json &json) {
//  GameObject::Deserialize(json);
}

}