//
// Created by rishi on 22-04-2021.
//
#define _USE_MATH_DEFINES
#include <cmath>
#include "ikaruga/core/objects/enemy/movement/movement_utils.h"

float ikaruga::objects::enemy::movement::MovementUtils::ComputeNextSineVelocity(
    float &current_degree,
    float amplitude,
    float period) {
//  float m_amplitude = 5.0f; // height
//  float m_period = 75.0f; // cycle time

  // Update degrees
  float degrees = 360.0f / period;
  current_degree = fmod(current_degree + degrees, 360.0f);
  float radians = current_degree * (float) M_PI / 180.0f;

  // Offset by sin wave
  return amplitude * sin(radians);
}

float ikaruga::objects::enemy::movement::MovementUtils::ComputeNextLinearVelocity(
    float velocity,
    float current_line_point,
    float line_width) {
  if (current_line_point < 0 || current_line_point >= line_width) {
    return -velocity;
  }
  return velocity;
}
