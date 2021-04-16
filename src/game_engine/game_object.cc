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
}