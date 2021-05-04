//
// Created by rishi on 22-04-2021.
//
#pragma once

namespace ikaruga::objects::enemy::movement {
// Utility class for movement behaviors that can be paired 
// to create a movement strategy
class MovementUtils {
 public:
  static float ComputeNextSineVelocity(float &current_degree,
                                       float amplitude,
                                       float period);
  static float ComputeNextLinearVelocity(
      float velocity,
      float current_line_point,
      float line_width);
};
} // namespace ikaruga::objects::enemy::movement