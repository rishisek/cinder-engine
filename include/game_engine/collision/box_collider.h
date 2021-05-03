//
// Created by rishi on 17-04-2021.
//
#pragma once
#include <serialization_utils/vec2_json.h>
#include <game_engine/collision/collider.h>

namespace game_engine {
class BoxCollider : public Collider {
 public:
  BoxCollider(const glm::vec2 &position, double width, double height);
  bool operator==(const BoxCollider &rhs) const;
  bool operator!=(const BoxCollider &rhs) const;

  bool IsCollision(const Collider &other) const override;
  const glm::vec2 &GetPosition() const;
  double GetHeight() const;
  double GetWidth() const;

  void Serialize(nlohmann::json &json) const override;
  void Deserialize(const nlohmann::json &json) override;

  friend class CollisionUtils;
 private:
  double width_;
  double height_;
};
}

namespace nlohmann {
template<>
struct adl_serializer<game_engine::BoxCollider> {
  // note: the return type is no longer 'void', and the method only takes
  // one argument
  static game_engine::BoxCollider from_json(const json &j);

  // Here's the catch! You must provide a to_json method! Otherwise you
  // will not be able to convert game_engine::BoxCollider to json, since you fully
  // specialized adl_serializer on that type
  static void to_json(json &j, game_engine::BoxCollider t);
};
}