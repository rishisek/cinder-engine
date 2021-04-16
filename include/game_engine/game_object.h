//
// Created by rishi on 16-04-2021.
//

#pragma once
#include <game_engine/collider.h>

namespace game_engine {
class GameObject {
 public:
  bool Collides(GameObject const &other);
 private:
  Collider collider_;
};
}