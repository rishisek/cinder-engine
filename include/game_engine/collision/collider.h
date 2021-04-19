//
// Created by rishi on 17-04-2021.
//
#pragma once

#include <glm/vec2.hpp>
namespace game_engine {
class Collider {
 public:
  virtual ~Collider() = 0;
  void SetPosition(const glm::vec2 &position);
  virtual bool IsCollision(Collider const &other) = 0;
 protected:
  Collider(glm::vec2 position);
  glm::vec2 position_;
};
}