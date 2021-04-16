//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/character_object.h>

namespace ikaruga {
class FlyerCharacter : public game_engine::CharacterObject {
 public:
  void Update() override;
};
}
