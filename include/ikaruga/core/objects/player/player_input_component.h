//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <game_engine/components/input_component.h>

namespace ikaruga::objects::player {
class PlayerInputComponent : public game_engine::InputComponent {
 public:
  void Update(game_engine::GameObject &game_object,
              game_engine::GameWorld &game_world) override;
  void receive(int message) override;
};
}
