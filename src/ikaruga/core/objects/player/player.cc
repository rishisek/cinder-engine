//
// Created by rishi on 16-04-2021.
//

#include "ikaruga/core/objects/player/player.h"

namespace ikaruga {

Player::Player(game_engine::PhysicsComponent *physics_component,
               game_engine::InputComponent *input_component,
               const std::vector<ProjectileType> &projectile_types,
               double view_angle_radians)
    : view_angle_radians_(view_angle_radians),
      ProjectileShooter(projectile_types),
      game_engine::ControllableObject<game_engine::CharacterObject>(physics_component, input_component) {}

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

bool Player::InCooldown() {
  return projectile_types_[current_projectile_type_index_].GetCurrentCooldown()
      != 0;
}

void Player::Update() {
  GameObject::Update();
  UpdateCooldowns();
}
}