//
// Created by rishi on 17-04-2021.
//

#include <glm/geometric.hpp>
#include "game_engine/collision/collision_utils.h"

namespace game_engine {
bool CollisionUtils::IsCollision(game_engine::CircleCollider const *circle,
                                 game_engine::BoxCollider const *box) {
  glm::vec2 closest_box_vertex = circle->position_;

  if (circle->position_.x < box->position_.x) {
    closest_box_vertex.x = box->position_.x;
  } else if
      (circle->position_.x
          > box->position_.x + box->width_) {
    closest_box_vertex.x = box->position_.x
        + static_cast<float>(box->width_);
  }

  if (circle->position_.y < box->position_.y) {
    closest_box_vertex.y = box->position_.y;
  } else if (circle->position_.y
      > box->position_.y + box->height_) {
    closest_box_vertex.y = box->position_.y
        + static_cast<float>(box->height_);
  }

  return (glm::distance(circle->position_, closest_box_vertex)
      <= circle->radius_);
}

bool CollisionUtils::IsCollision(const CircleCollider *circle1,
                                 const CircleCollider *circle2) {
  return glm::distance(circle1->position_, circle2->position_)
      <= circle1->radius_ + circle2->radius_;
}
}