//
// Created by rishi on 17-04-2021.
//
#pragma once
#include <game_engine/json_serializable.h>
#include <glm/vec2.hpp>
#include <nlohmann/json.hpp>

namespace game_engine {
class Collider : public JsonSerializable {
 public:
  virtual ~Collider() = 0;
  bool operator==(const Collider &rhs) const;
  bool operator!=(const Collider &rhs) const;

  virtual bool IsCollision(Collider const &other) const = 0;
  void UpdatePosition(const glm::vec2 &velocity);

  virtual void Serialize(nlohmann::json &json) const override;
  virtual void Deserialize(const nlohmann::json &json) override;
 protected:
  Collider(glm::vec2 position);
  glm::vec2 position_;
};
void to_json(nlohmann::json &json, const Collider &collider);
void from_json(const nlohmann::json &json, Collider &collider);
}