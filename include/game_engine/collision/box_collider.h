//
// Created by rishi on 17-04-2021.
//
#pragma once

#include <glm/vec2.hpp>
#include "collider.h"

namespace game_engine {
class BoxCollider : public Collider {
 public:
  BoxCollider(const glm::vec2 &position, double width, double height);

  bool IsCollision(const Collider &other) override;
  const glm::vec2 &GetPosition() const;
  double GetHeight() const;
  double GetWidth() const;

  friend class CollisionUtils;
 private:
  double width_;
  double height_;
};
}