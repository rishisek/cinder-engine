//
// Created by rishi on 17-04-2021.
//

#include <game_engine/collision/circle_collider.h>
#include <game_engine/collision/box_collider.h>
#include <game_engine/collision/collision_utils.h>
#include <cinder/gl/gl.h>

namespace game_engine {
bool CircleCollider::IsCollision(const game_engine::Collider &other) const {
  if (const CircleCollider
      *circle_collider = dynamic_cast<const CircleCollider *>(&other)) {
    // safely casted
    return CollisionUtils::IsCollision(this, circle_collider);
  } else if (const BoxCollider
      *box_collider = dynamic_cast<const BoxCollider *>(&other)) {
    // safely casted
    return CollisionUtils::IsCollision(this, box_collider);
  }
  return false;
}

CircleCollider::CircleCollider(const glm::vec2 &position, double radius)
    : Collider(position), radius_(radius) {}

void CircleCollider::Serialize(nlohmann::json &json) const {
  Collider::Serialize(json);
  json["radius"] = radius_;
}

void CircleCollider::Deserialize(const nlohmann::json &json) {
  Collider::Deserialize(json);
  radius_ = json.at("radius");
}

bool CircleCollider::operator==(const CircleCollider &rhs) const {
  return static_cast<const game_engine::Collider &>(*this)
      == static_cast<const game_engine::Collider &>(rhs) &&
      radius_ == rhs.radius_;
}

bool CircleCollider::operator!=(const CircleCollider &rhs) const {
  return !(rhs == *this);
}

void CircleCollider::Draw() const {
  ci::gl::color(1, 0, 0);
  ci::gl::drawStrokedCircle(position_, (float) radius_);
}
}

namespace nlohmann {
game_engine::CircleCollider adl_serializer<game_engine::CircleCollider>::from_json(
    const json &j) {
  return {j.at("position"), j.at("radius")};
}

void adl_serializer<game_engine::CircleCollider>::to_json(json &j,
                                                          game_engine::CircleCollider t) {
  t.Serialize(j);
}
}