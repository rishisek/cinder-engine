//
// Created by rishi on 16-04-2021.
//
#pragma once
#include <vector>
#include <game_engine/json_serializable.h>
#include <game_engine/collision/collider.h>

namespace game_engine {
class ColliderMesh : public JsonSerializable {
 public:
  ColliderMesh() = default;
  // TODO: Fix deserialization to allow default copy constructor.
  ColliderMesh(const ColliderMesh &) = delete;
  ColliderMesh(ColliderMesh &&) = default;

  void Draw() const;

  bool IsCollision(ColliderMesh const &other) const;
  void AddCollider(game_engine::Collider *collider);
  const std::vector<Collider *> &GetColliders() const;
  void Serialize(nlohmann::json &json) const override;
  void Deserialize(const nlohmann::json &json) override;
  virtual ~ColliderMesh();
 private:
  std::vector<Collider *> colliders_;
};

void to_json(nlohmann::json &json, const ColliderMesh &mesh);

void from_json(const nlohmann::json &json, ColliderMesh &mesh);
}