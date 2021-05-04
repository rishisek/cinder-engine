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
               game_engine::GraphicsComponent *graphics_component,
               const std::vector<ProjectileType *> &projectile_types,
               double view_angle_radians)
    : game_engine::ControllableObject<ProjectileShooter>(
    std::move(new ProjectileShooter(physics_component,
                                    projectile_types,
                                    glm::vec2(38, 0))),
    input_component),
      graphics_component_(graphics_component),
      view_angle_radians_(view_angle_radians) {
  shoot_angle_radians_ = kNormalAngle;
}

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

void Player::Update(game_engine::GameWorld &world) {
  GameObject::Update(world);
  UpdateCooldowns();
  input_component_->Update(*this, dynamic_cast<world::World &>(world));
  graphics_component_->Update(
      graphics_component_->GetPosition() + physics_component_->GetVelocity());
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

game_engine::GraphicsComponent *const &Player::GetGraphicsComponent() const {
  return graphics_component_;
}
}