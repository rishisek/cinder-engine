//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <ikaruga/core/world/world.h>
#include "game_engine/objects/game_object.h"
#include "component.h"

namespace game_engine {
class InputComponent : public Component {
 public:
  virtual ~InputComponent() = 0;

  virtual void Update(game_engine::GameObject &game_object,
                      game_engine::GameWorld &game_world) = 0;

 protected:
  InputComponent() = default;
};
}