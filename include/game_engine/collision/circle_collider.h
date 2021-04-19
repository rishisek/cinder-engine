//
// Created by rishi on 17-04-2021.
//
#pragma once

#include <glm/vec2.hpp>
#include "collider.h"

namespace game_engine {
class CircleCollider : public Collider {
 public:
  CircleCollider(const glm::vec2 &position, double radius);
  bool IsCollision(const Collider &other) override;

  friend class CollisionUtils;
 private:
  double radius_;
};
}