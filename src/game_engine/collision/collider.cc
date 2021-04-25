//
// Created by rishi on 17-04-2021.
//
#include <game_engine/collision/collider.h>
#include <game_engine/vec2_json.h>

namespace game_engine {
Collider::~Collider() {

}

void Collider::UpdatePosition(const glm::vec2 &velocity) {
  position_ += velocity;
}

Collider::Collider(glm::vec2 position) : position_(position) {}

void Collider::Serialize(nlohmann::json &json) const {
  json["position"] = position_;
}

void Collider::Deserialize(const nlohmann::json &json) {
  position_ = json["position"];
}

bool Collider::operator==(const Collider &rhs) const {
  return position_ == rhs.position_;
}

bool Collider::operator!=(const Collider &rhs) const {
  return !(rhs == *this);
}

void to_json(nlohmann::json &json, const Collider &collider) {
  collider.Serialize(json);
}

void from_json(const nlohmann::json &json, Collider &collider) {
  collider.Deserialize(json);
}
}