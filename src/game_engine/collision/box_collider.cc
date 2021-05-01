//
// Created by rishi on 17-04-2021.
//

#include "game_engine/collision/box_collider.h"
#include <game_engine/collision/circle_collider.h>
#include <game_engine/collision/collision_utils.h>
#include <cinder/gl/gl.h>

namespace game_engine {

bool BoxCollider::IsCollision(const Collider &other) const {
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

const glm::vec2 &BoxCollider::GetPosition() const {
  return position_;
}

double BoxCollider::GetWidth() const {
  return width_;
}

double BoxCollider::GetHeight() const {
  return height_;
}

BoxCollider::BoxCollider(const glm::vec2 &position, double width, double height)
    : Collider(position), width_(width), height_(height) {}

void BoxCollider::Serialize(nlohmann::json &json) const {
  Collider::Serialize(json);
  json["width"] = width_;
  json["height"] = height_;
}

void BoxCollider::Deserialize(const nlohmann::json &json) {
  Collider::Deserialize(json);
  width_ = json.at("width");
  height_ = json.at("height");
}

bool BoxCollider::operator==(const BoxCollider &rhs) const {
  return static_cast<const game_engine::Collider &>(*this)
      == static_cast<const game_engine::Collider &>(rhs) &&
      width_ == rhs.width_ &&
      height_ == rhs.height_;
}

bool BoxCollider::operator!=(const BoxCollider &rhs) const {
  return !(rhs == *this);
}

void BoxCollider::Draw() const {
  ci::gl::color(1, 0, 0);
  ci::gl::drawStrokedRect(ci::Rectf(position_,
                                    position_ + glm::vec2(width_, height_)));
}
}

namespace nlohmann {
game_engine::BoxCollider adl_serializer<game_engine::BoxCollider>::from_json(
    const json &j) {
  return {j.at("position"), j.at("width"), j.at("height")};
}

void adl_serializer<game_engine::BoxCollider>::to_json(json &j,
                                                       game_engine::BoxCollider t) {
  t.Serialize(j);
}
}