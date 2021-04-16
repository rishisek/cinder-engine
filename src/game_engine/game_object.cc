//
// Created by rishi on 16-04-2021.
//

#include "game_engine/game_object.h"

namespace game_engine {
bool GameObject::Collides(const game_engine::GameObject &other) {
  return this->collider_.IsCollision(other.collider_);
}
}