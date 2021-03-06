//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/objects/controllable_object.h>
#include <ikaruga/core/objects/projectile/projectile_shooter.h>
#include <ikaruga/core/objects/player/player_graphics_component.h>

namespace ikaruga::objects::player {
class Player
    : public game_engine::ControllableObject<projectile::ProjectileShooter> {
 public:
  Player(game_engine::PhysicsComponent *physics_component,
         game_engine::InputComponent *input_component,
         game_engine::GraphicsComponent *graphics_component,
         const std::vector<projectile::ProjectileType *> &projectile_types,
         double view_angle_radians = M_PI / 3.0);
  void Update(game_engine::GameWorld &world) override;
  void TiltAimLeft();
  void TiltAimRight();

  void IncrementScore(int score_increment);
  int GetScore() const;
  void TakeDamage();

  game_engine::GraphicsComponent *const &GetGraphicsComponent() const;

  friend class PlayerInputComponent;
  friend class PlayerPhysicsComponent;
  friend class PlayerGraphicsComponent;
 private:
  static constexpr int kMaxHealth = 25;
  const double kNormalAngle = -M_PI / 2.0;
  const double kAimStep = 0.01;

  game_engine::GraphicsComponent *graphics_component_;
  double view_angle_radians_;
  int score_ = 0;

  // Sends a message to all member components (Mediator pattern)
  void send(int message);
};
}