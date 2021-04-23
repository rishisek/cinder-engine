//
// Created by rishi on 16-04-2021.
//

#pragma once

#include <vector>
#include "collider.h"

namespace game_engine {
class ColliderMesh {
 public:
  bool IsCollision(ColliderMesh const &other) const;
  void AddCollider(game_engine::Collider *collider);
  const std::vector<Collider *> &GetColliders() const;
  virtual ~ColliderMesh();
 private:
  std::vector<Collider *> colliders_;
};
}