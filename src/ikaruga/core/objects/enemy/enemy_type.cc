//
// Created by rishi on 16-04-2021.
//

#include <vector>
#include "ikaruga/core/objects/enemy/enemy_type.h"

namespace ikaruga::objects::enemy {
int EnemyType::GetMaxHealth() const {
  return max_health_;
}

const std::vector<projectile::ProjectileType> &EnemyType::GetProjectileTypes() const {
  return projectile_types_;
}

EnemyType::EnemyType(int max_health,
                     ikaruga::objects::enemy::movement::Pattern pattern,
                     const std::vector<projectile::ProjectileType> &projectile_types,
                     const ci::Color &color)
    : max_health_(max_health),
      pattern_(pattern),
      projectile_types_(projectile_types),
      color_(color) {}

const ci::ColorT<float> &EnemyType::GetColor() const {
  return color_;
}

void EnemyType::Serialize(nlohmann::json &json) const {
  json["max_health"] = max_health_;
  json["pattern"] = pattern_;
  json["projectile_types"] = projectile_types_;
  json["color"] = color_;
}

void EnemyType::Deserialize(const nlohmann::json &json) {
  max_health_ = json["max_health"];
  pattern_ = json["pattern"];
  projectile_types_ =
      json["projectile_types"].get<std::vector<projectile::ProjectileType>>();
  color_ = json["color"];
}

bool EnemyType::operator==(const EnemyType &rhs) const {
  return max_health_ == rhs.max_health_ &&
      pattern_ == rhs.pattern_ &&
      projectile_types_ == rhs.projectile_types_ &&
      color_ == rhs.color_;
}

bool EnemyType::operator!=(const EnemyType &rhs) const {
  return !(rhs == *this);
}
}

namespace nlohmann {
ikaruga::objects::enemy::EnemyType adl_serializer<ikaruga::objects::enemy::EnemyType>::from_json(
    const json &j) {
  return {j.at("max_health"), j.at("pattern"), j.at("projectile_types"),
          j.at("color")};
}

void adl_serializer<ikaruga::objects::enemy::EnemyType>::to_json(json &j,
                                                                 ikaruga::objects::enemy::EnemyType t) {
  t.Serialize(j);
}
}