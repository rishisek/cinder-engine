//
// Created by rishi on 17-04-2021.
//

#include "game_engine/collision/circle_collider.h"
#include <glm/geometric.hpp>
#include <game_engine/collision/box_collider.h>
#include <game_engine/collision/collision_utils.h>

namespace game_engine {
bool CircleCollider::IsCollision(const game_engine::Collider &other) {
  if (const CircleCollider
      *circle_collider = dynamic_cast<const CircleCollider *>(&other)) {
    // safely casted
    return CollisionUtils::IsCollision(this, circle_collider);
  }
  return false;
}

CircleCollider::CircleCollider(const glm::vec2 &position, double radius)
    : position_(position), radius_(radius) {}

}