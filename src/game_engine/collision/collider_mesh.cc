//
// Created by rishi on 16-04-2021.
//

#include <game_engine/collision/circle_collider.h>
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

void ColliderMesh::Serialize(nlohmann::json &json) const {
  for (size_t i = 0; i < colliders_.size(); ++i) {
    json[i] = *colliders_[i];
  }
}

void ColliderMesh::Deserialize(const nlohmann::json &json) {
  for (const nlohmann::json &collider_json: json) {
    Collider *collider = nullptr;
    collider = new CircleCollider(collider_json);
    colliders_.push_back(collider);
  }
}

void to_json(nlohmann::json &json, const ColliderMesh &mesh) {
  mesh.Serialize(json);
}

void from_json(const nlohmann::json &json, ColliderMesh &mesh) {
  mesh.Deserialize(json);
}
}