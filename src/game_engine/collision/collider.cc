//
// Created by rishi on 17-04-2021.
//

#include "game_engine/collision/collider.h"

namespace game_engine {
Collider::~Collider() {

}

void Collider::SetPosition(const glm::vec2 &position) {
  position_ = position;
}

Collider::Collider(glm::vec2 position) : position_(position) {}
}