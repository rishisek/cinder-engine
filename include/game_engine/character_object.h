//
// Created by rishi on 16-04-2021.
//
#pragma once

#include "game_object.h"

namespace game_engine {
class CharacterObject : public GameObject {
 public:
 protected:
  CharacterObject(const glm::vec2 &position,
                  const glm::vec2 &velocity);
  float max_health_;
  float health_;
};
}