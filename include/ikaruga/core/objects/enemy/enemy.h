//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/character_object.h>
#include "enemy_type.h"

namespace ikaruga {
class Enemy : public game_engine::CharacterObject {
 public:
  void Update() override;
 private:
};
}