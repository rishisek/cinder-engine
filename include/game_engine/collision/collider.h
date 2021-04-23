//
// Created by rishi on 17-04-2021.
//
#pragma once

#include <glm/vec2.hpp>
namespace game_engine {
class Collider {
 public:
  virtual ~Collider() = 0;
  virtual bool IsCollision(Collider const &other) = 0;
  void UpdatePosition(const glm::vec2 &velocity);
 protected:
  Collider(glm::vec2 position);
  glm::vec2 position_;
};
}