//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/input_component.h>

namespace ikaruga {
class PlayerInputComponent : public game_engine::InputComponent {
 public:
  void Update(game_engine::GameObject &game_object) override;
};
}
