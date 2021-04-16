//
// Created by rishi on 16-04-2021.
//
#pragma once

#include "game_object.h"

namespace game_engine {
class InputComponent {
 public:
  virtual ~InputComponent() {}

  virtual void Update(GameObject &game_object) = 0;
};
}