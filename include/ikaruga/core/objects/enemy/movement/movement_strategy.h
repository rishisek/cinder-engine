//
// Created by rishi on 02-05-2021.
//
#pragma once
#include <glm/vec2.hpp>

namespace ikaruga::objects::enemy::movement {
// Base movement strategy template
class MovementStrategy {
 public:
  virtual glm::vec2 GetNextVelocity(const glm::vec2 &current_velocity) = 0;
};
} // namespace ikaruga::objects::enemy::movement