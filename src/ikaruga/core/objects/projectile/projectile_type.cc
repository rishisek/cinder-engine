//
// Created by rishi on 16-04-2021.
//
#include <ikaruga/core/objects/projectile/projectile_type.h>
#include <serialization_utils/cinder_color_json.h>

namespace ikaruga::objects::projectile {
ProjectileType::ProjectileType(float radius,
                               const cinder::ColorT<float> &color,
                               int cooldown)
    : radius_(radius),
      color_(color),
      cooldown_(cooldown) {}

float ProjectileType::GetRadius() const {
  return radius_;
}

const cinder::ColorT<float> &ProjectileType::GetColor() const {
  return color_;
}

int ProjectileType::GetCurrentCooldown() const {
  return current_cooldown_;
}

void ProjectileType::DecrementCurrentCooldown() {
  current_cooldown_--;
  if (current_cooldown_ <= 0) {
    current_cooldown_ = 0;
  }
}

void ProjectileType::StartCooldown() {
  current_cooldown_ = cooldown_;
}

bool ProjectileType::operator==(const ProjectileType &other) const {
  return radius_ == other.radius_ && color_ == other.color_
      && cooldown_ == other.cooldown_;
}

void ProjectileType::Serialize(nlohmann::json &json) const {
  json["radius"] = radius_;
  json["color"] = color_;
  json["cooldown"] = cooldown_;
}

void ProjectileType::Deserialize(const nlohmann::json &json) {
  radius_ = json["radius"];
  color_ = json["color"];
  cooldown_ = json["cooldown"];
}
}

namespace nlohmann {
ikaruga::objects::projectile::ProjectileType adl_serializer<ikaruga::objects::projectile::ProjectileType>::from_json(
    const json &j) {
  return {j.at("radius"), j.at("color"), j.at("cooldown")};
}

void adl_serializer<ikaruga::objects::projectile::ProjectileType>::to_json(json &j,
                                                                           ikaruga::objects::projectile::ProjectileType t) {
  t.Serialize(j);
}
}