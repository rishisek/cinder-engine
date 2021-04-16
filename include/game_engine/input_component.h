//
// Created by rishi on 16-04-2021.
//
#pragma once

#include <ikaruga/core/objects/world/world.h>
#include "game_object.h"

namespace game_engine {
class InputComponent {
 public:
  virtual ~InputComponent() {}

  virtual void Update(game_engine::GameObject &game_object,
                      ikaruga::World &world) = 0;
};
}