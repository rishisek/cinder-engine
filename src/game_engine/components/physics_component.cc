//
// Created by rishi on 16-04-2021.
//

#include "game_engine/components/physics_component.h"

namespace game_engine {
void PhysicsComponent::UpdatePosition() {
  position_ += velocity_;
}

bool PhysicsComponent::Collides(const GameObject &other) {
  return collider_.IsCollision(other.GetPhysicsComponent()->collider_);
}

const glm::vec2 &PhysicsComponent::GetPosition() const {
  return position_;
}

void PhysicsComponent::SetPosition(const glm::vec2 &position) {
  position_ = position;
}

const glm::vec2 &PhysicsComponent::GetVelocity() const {
  return velocity_;
}

void PhysicsComponent::SetVelocity(const glm::vec2 &velocity) {
  velocity_ = velocity;
}
}