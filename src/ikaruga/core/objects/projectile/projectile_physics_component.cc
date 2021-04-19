//
// Created by rishi on 16-04-2021.
//

#include <game_engine/collision/circle_collider.h>
#include "ikaruga/core/objects/projectile/projectile_physics_component.h"

namespace ikaruga {
void ProjectilePhysicsComponent::Update() {
  PhysicsComponent::Update();
}

void ProjectilePhysicsComponent::receive(int message) {

}

ProjectilePhysicsComponent::ProjectilePhysicsComponent(const glm::vec2 &position,
                                                       const glm::vec2 &velocity,
                                                       double radius)
    : PhysicsComponent(position, velocity) {

}
}