//
// Created by rishi on 16-04-2021.
//
#pragma once

#include "flyer_character.h"

namespace ikaruga {
class Player : public FlyerCharacter {
 public:
  Player(const std::vector<ProjectileType> &projectile_types,
         const glm::vec2 &position,
         const glm::vec2 &velocity);
};
}