//
// Created by rishi on 16-04-2021.
//
#pragma once

#include "flyer_character.h"

namespace ikaruga {
class Player : public FlyerCharacter {
 public:
  Player(const glm::vec2 &position,
         const glm::vec2 &velocity,
         const std::vector<ProjectileType> &projectile_types,
         double view_angle_radians = M_PI / 3.0);
  
  void TiltAimLeft();
  void TiltAimRight();
  bool InCooldown();
 private:
  const double kAimStep = 0.1;
  double view_angle_radians_;
};
}