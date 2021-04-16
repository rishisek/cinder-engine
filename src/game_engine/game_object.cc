//
// Created by rishi on 16-04-2021.
//

#include "game_engine/game_object.h"

namespace game_engine {
void GameObject::UpdatePosition() {
  position_+=velocity_;
}

bool GameObject::Collides(const GameObject &other) {
  return collider_.IsCollision(other.collider_);
}

const glm::vec2 &GameObject::GetPosition() const {
  return position_;
}

void GameObject::SetPosition(const glm::vec2 &position) {
  position_ = position;
}

const glm::vec2 &GameObject::GetVelocity() const {
  return velocity_;
}

void GameObject::SetVelocity(const glm::vec2 &velocity) {
  velocity_ = velocity;
}
}