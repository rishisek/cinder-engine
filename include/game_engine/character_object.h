//
// Created by rishi on 16-04-2021.
//
#pragma once

#include "game_object.h"

namespace game_engine {
class CharacterObject : public GameObject {
 public:
  void Update() override;
 private:
  int max_health_;
  int health_;
};
}