//
// Created by rishi on 22-04-2021.
//
#include <ikaruga/core/objects/enemy/movement/sine_loop_movement_strategy.h>
#include <ikaruga/core/objects/enemy/movement/movement_utils.h>

namespace ikaruga::objects::enemy::movement {
glm::vec2 SineLoopMovementStrategy::GetNextVelocity(const glm::vec2 &current_velocity) {
  glm::vec2 next_velocity;
  next_velocity.x =
      MovementUtils::ComputeNextSineVelocity(current_sine_x_degree_,
                                             4.5f,
                                             400.0f);
  next_velocity.y =
      MovementUtils::ComputeNextSineVelocity(current_sine_y_degree_,
                                             10.0f,
                                             50.0f);
  return next_velocity;
}
}