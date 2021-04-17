//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/objects/controllable_object.h>
#include "ikaruga/core/objects/projectile/projectile_shooter.h"

namespace ikaruga {
class Player
    : public ProjectileShooter,
      public game_engine::ControllableObject<game_engine::CharacterObject> {
 public:
  Player(game_engine::PhysicsComponent *physics_component,
         game_engine::InputComponent *input_component,
         const std::vector<ProjectileType> &projectile_types,
         double view_angle_radians = M_PI / 3.0);
  void Update(game_engine::GameObject &world) override;
  void TiltAimLeft();
  void TiltAimRight();
  bool InCooldown();
  
  friend class PlayerInputComponent;
  friend class PlayerPhysicsComponent;
 private:
  const double kAimStep = 0.1;
  double view_angle_radians_;
  void send(int message);
};
}