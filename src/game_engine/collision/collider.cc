//
// Created by rishi on 17-04-2021.
//

#include "game_engine/collision/collider.h"

namespace game_engine {
Collider::~Collider() {

}

void Collider::UpdatePosition(const glm::vec2 &velocity) {
  position_ += velocity;
}

Collider::Collider(glm::vec2 position) : position_(position) {}
}