//
// Created by rishi on 17-04-2021.
//
#pragma once
#include <serialization_utils/vec2_json.h>
#include <game_engine/collision/collider.h>

namespace game_engine {
class CircleCollider : public Collider {
 public:
  CircleCollider(const glm::vec2 &position, double radius);
  CircleCollider(const CircleCollider &) = default;
  CircleCollider(CircleCollider &&) = default;
  bool operator==(const CircleCollider &rhs) const;
  bool operator!=(const CircleCollider &rhs) const;

  bool IsCollision(const Collider &other) const override;
  void Draw() const override;

  void Serialize(nlohmann::json &json) const override;
  void Deserialize(const nlohmann::json &json) override;

  friend class CollisionUtils;
 private:
  double radius_;
};
}

namespace nlohmann {
template<>
struct adl_serializer<game_engine::CircleCollider> {
  // note: the return type is no longer 'void', and the method only takes
  // one argument
  static game_engine::CircleCollider from_json(const json &j);

  // Here's the catch! You must provide a to_json method! Otherwise you
  // will not be able to convert game_engine::CircleCollider to json, since you fully
  // specialized adl_serializer on that type
  static void to_json(json &j, game_engine::CircleCollider t);
};
}