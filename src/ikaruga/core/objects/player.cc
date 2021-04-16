//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/player.h"

namespace ikaruga {
Player::Player(const glm::vec2 &position,
               const glm::vec2 &velocity,
               const std::vector<ProjectileType> &projectile_types,
               double view_angle_radians)
    : view_angle_radians_(view_angle_radians),
      FlyerCharacter(projectile_types, position, velocity) {}

void Player::TiltAimLeft() {
  shoot_angle_radians_ -= kAimStep;
  if (shoot_angle_radians_ <= kNormalAngle - view_angle_radians_ / 2) {
    shoot_angle_radians_ = kNormalAngle - view_angle_radians_ / 2;
  }
}

void Player::TiltAimRight() {
  shoot_angle_radians_ += kAimStep;
  if (shoot_angle_radians_ >= kNormalAngle + view_angle_radians_ / 2) {
    shoot_angle_radians_ = kNormalAngle + view_angle_radians_ / 2;
  }
}
}