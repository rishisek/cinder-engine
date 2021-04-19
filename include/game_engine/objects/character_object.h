//
// Created by rishi on 16-04-2021.
//
#pragma once

#include "game_object.h"

namespace game_engine {
class CharacterObject : public GameObject {
 public:
  virtual ~CharacterObject() = 0;
 protected:
  CharacterObject(PhysicsComponent *physics_component);
  float max_health_;
  float health_;
};
}