//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/projectile/projectile_physics_component.h"

namespace ikaruga{
void ProjectilePhysicsComponent::Update() {
  UpdatePosition();
}

void ProjectilePhysicsComponent::receive(int message) {

}
}