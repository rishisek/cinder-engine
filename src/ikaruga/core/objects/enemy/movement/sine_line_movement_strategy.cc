//
// Created by rishi on 22-04-2021.
//
#include <ikaruga/core/objects/enemy/movement/sine_line_movement_strategy.h>
#include <ikaruga/core/objects/enemy/movement/movement_utils.h>

namespace ikaruga::objects::enemy::movement {
glm::vec2 SineLineMovementStrategy::GetNextVelocity(const glm::vec2 &current_velocity) {
  glm::vec2 next_velocity;
  next_velocity.x =
      MovementUtils::ComputeNextLinearVelocity(current_velocity.x,
                                               current_line_point_,
                                               period_ * period_count_);
  current_line_point_ += next_velocity.x;
  next_velocity.y =
      MovementUtils::ComputeNextSineVelocity(current_sine_y_degree_,
                                             amplitude_,
                                             period_);
  return next_velocity;
}
}