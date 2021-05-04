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

int ProjectileType::GetCooldown() const {
  return cooldown_;
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