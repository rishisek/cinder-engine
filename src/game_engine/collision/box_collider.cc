//
// Created by rishi on 17-04-2021.
//

#include "game_engine/collision/box_collider.h"

namespace game_engine {

bool BoxCollider::IsCollision(const Collider &other) {
  return false;
}

const glm::vec2 &BoxCollider::GetPosition() const {
  return position_;
}

double BoxCollider::GetWidth() const {
  return width_;
}

double BoxCollider::GetHeight() const {
  return height_;
}

}