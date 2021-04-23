//
// Created by rishi on 16-04-2021.
//

#include "game_engine/collision/collider_mesh.h"

namespace game_engine {
bool ColliderMesh::IsCollision(const ColliderMesh &other) const {
  for (Collider *collider: colliders_) {
    for (Collider *other_collider: other.colliders_) {
      if (collider->IsCollision(*other_collider)) {
        return true;
      }
    }
  }
  return false;
}

void ColliderMesh::AddCollider(game_engine::Collider *collider) {
  colliders_.push_back(collider);
}

ColliderMesh::~ColliderMesh() {
  for (Collider *collider: colliders_) {
    delete collider;
  }
}

const std::vector<Collider *> &ColliderMesh::GetColliders() const {
  return colliders_;
}
}