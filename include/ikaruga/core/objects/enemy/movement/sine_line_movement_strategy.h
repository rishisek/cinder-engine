//
// Created by rishi on 22-04-2021.
//
#pragma once

#include <game_engine/components/physics_component.h>
#include <ikaruga/core/objects/enemy/movement/movement_strategy.h>

namespace ikaruga::objects::enemy::movement {
class SineLineMovementStrategy : public MovementStrategy {
 public:
  glm::vec2 GetNextVelocity(const glm::vec2 &current_velocity) override;
 private:
  int period_count_ = 5;
  float period_ = 75.0f;
  float amplitude_ = 5.0f;
  float current_sine_y_degree_ = 90.0f;
  float current_line_point_ = period_ * period_count_ / 2;
};
} // namespace ikaruga::objects::enemy::movement