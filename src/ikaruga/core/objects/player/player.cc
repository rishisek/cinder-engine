//
// Created by rishi on 16-04-2021.
//

#include <ikaruga/core/objects/player/player.h>
#include <game_engine/components/physics_component.h>
#include <game_engine/components/input_component.h>

namespace ikaruga::objects::player {
using projectile::ProjectileShooter;
using projectile::ProjectileType;

Player::Player(game_engine::PhysicsComponent *physics_component,
               game_engine::InputComponent *input_component,
               const std::vector<ProjectileType> &projectile_types,
               double view_angle_radians)
    : ProjectileShooter(projectile_types),
      game_engine::ControllableObject<game_engine::CharacterObject>(
          physics_component,
          input_component),
      graphics_component_(physics_component_->GetPosition()),
      view_angle_radians_(view_angle_radians) {}

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

void Player::Update(game_engine::GameWorld &world) {
  GameObject::Update(world);
  UpdateCooldowns();
  input_component_->Update(*this, dynamic_cast<world::World &>(world));
  graphics_component_.Update(physics_component_->GetPosition());
}

void Player::send(int message) {
  physics_component_->receive(message);
}

void Player::IncrementScore(int score) {
  score_ += score;
}

int Player::GetScore() const {
  return score_;
}

const PlayerGraphicsComponent &Player::GetGraphicsComponent() const {
  return graphics_component_;
}
}