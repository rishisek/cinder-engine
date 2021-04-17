//
// Created by rishi on 16-04-2021.
//

#pragma once

namespace game_engine {
class ColliderMesh {
 public:
  bool IsCollision(ColliderMesh const &other);
};
}