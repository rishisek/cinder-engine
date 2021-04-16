//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/game_object.h>

namespace ikaruga {
class Player : public game_engine::GameObject {
 public:
  void Update() override;
 private:
  int max_health_;
  int health_;
};
}